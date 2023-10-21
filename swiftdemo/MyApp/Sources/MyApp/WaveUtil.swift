import Foundation

class WaveUtil {
  static let WAV_HEADER_SIZE = 44
  static let RECORDING_FILE = "MicInput.wav"
  
  func createWaveFile(filePath: String, samples: [UInt8], sampleRate: Int, numChannels: Int, bytesPerSample: Int) {
    let dataSize = samples.count // actual data size in bytes
    let audioFormat: Int = (bytesPerSample == 2) ? 1 : (bytesPerSample == 4) ? 3 : 0 // PCM_16 = 1, PCM_FLOAT = 3
    
    do {
      let fileURL = URL(fileURLWithPath: filePath)
      let fileOutputStream = try FileHandle(forWritingTo: fileURL)
      
      // Write the "RIFF" chunk descriptor
      fileOutputStream.write("RIFF".data(using: .utf8)!)
      // Total file size - 8 bytes
      fileOutputStream.write(Data(WaveUtil.intToByteArray(value: 36 + dataSize)))
      // Write the "WAVE" format
      fileOutputStream.write("WAVE".data(using: .utf8)!)
      // Write the "fmt " sub-chunk
      fileOutputStream.write("fmt ".data(using: .utf8)!)
      // Sub-chunk size (16 for PCM)
      fileOutputStream.write(Data(WaveUtil.intToByteArray(value: 16)))
      // Audio format (1 for PCM)
      fileOutputStream.write(Data(WaveUtil.shortToByteArray(value: audioFormat)))
      // Number of channels
      fileOutputStream.write(Data(WaveUtil.shortToByteArray(value: numChannels)))
      // Sample rate
      fileOutputStream.write(Data(WaveUtil.intToByteArray(value: sampleRate)))
      // Byte rate
      fileOutputStream.write(Data(WaveUtil.intToByteArray(value: sampleRate * numChannels * bytesPerSample)))
      // Block align
      fileOutputStream.write(Data(WaveUtil.shortToByteArray(value: numChannels * bytesPerSample)))
      // Bits per sample
      fileOutputStream.write(Data(WaveUtil.shortToByteArray(value: bytesPerSample * 8)))
      // Write the "data" sub-chunk
      fileOutputStream.write("data".data(using: .utf8)!)
      // Data size
      fileOutputStream.write(Data(WaveUtil.intToByteArray(value: dataSize)))
      // Write audio samples
      fileOutputStream.write(Data(samples))
      
      // Close the file output stream
      fileOutputStream.closeFile()
    } catch {
      print("An error occurred: \(error.localizedDescription)")
    }
  }
  
  static func getSamples(from filePath: String) -> [Float] {
    do {
      let fileURL = URL(fileURLWithPath: filePath)
      let fileData = try Data(contentsOf: fileURL)
      
      // Validate the WAV file
      let riffHeader = String(data: fileData[..<4], encoding: .utf8)
      guard riffHeader == "RIFF" else {
        print("Not a valid WAV file")
        return []
      }
      
      let sampleRate = WaveUtil.byteArrayToNumber(bytes: fileData, offset: 24, length: 4)
      let bitsPerSample = WaveUtil.byteArrayToNumber(bytes: fileData, offset: 34, length: 2)
      guard (bitsPerSample == 16) || (bitsPerSample == 32) else {
        print("Unsupported bits per sample: \(bitsPerSample)")
        return []
      }
      
      // Extract the audio data
      let audioData = fileData[44...]
      var samples: [Float] = []
      
      var dataIndex = audioData.startIndex
      let end = audioData.endIndex
      if bitsPerSample == 16 {
        while dataIndex < end {
          let sampleValue = audioData[dataIndex..<(dataIndex+2)].withUnsafeBytes {
            $0.load(as: Int16.self)
          }
          samples.append(Float(sampleValue) / 32768.0)
          dataIndex += 2
        }
      } else if bitsPerSample == 32 {
        while dataIndex < end {
          let sampleValue = audioData[dataIndex..<(dataIndex+4)].withUnsafeBytes {
            $0.load(as: Float.self)
          }
          samples.append(sampleValue)
          dataIndex += 4
        }
      }
      
      return samples
    } catch {
      print(error.localizedDescription)
      return []
    }
  }
  
  // Convert a portion of a Data object into an integer or a short
  private static func byteArrayToNumber(bytes: Data, offset: Int, length: Int) -> Int {
    var value: Int = 0  // Start with an initial value of 0
    
    // Loop through the specified portion of the byte array
    for i in 0..<length {
      // Extract a byte, ensure it's positive, and shift it to its position in the integer
      let byteValue = Int(bytes[offset + i])
      value |= (byteValue & 0xFF) << (8 * i)
    }
    
    return value  // Return the resulting integer value
  }
  
  private static func intToByteArray(value: Int) -> [UInt8] {
    var byteArray = [UInt8](repeating: 0, count: 4)  // Create a 4-byte array
    
    // Convert and store the bytes in little-endian order
    byteArray[0] = UInt8(value & 0xFF)  // Least significant byte (LSB)
    byteArray[1] = UInt8((value >> 8) & 0xFF)  // Second least significant byte
    byteArray[2] = UInt8((value >> 16) & 0xFF)  // Second most significant byte
    byteArray[3] = UInt8((value >> 24) & 0xFF)  // Most significant byte (MSB)
    
    return byteArray
  }
  
  private static func shortToByteArray(value: Int) -> [UInt8] {
    var byteArray = [UInt8](repeating: 0, count: 2)  // Create a 2-byte array
    
    // Convert and store the bytes in little-endian order
    byteArray[0] = UInt8(value & 0xFF)  // Least significant byte (LSB)
    byteArray[1] = UInt8((value >> 8) & 0xFF)  // Most significant byte (MSB)
    
    return byteArray
  }
  
  private static func byteArrayToInt(bytes: Data, offset: Int, length: Int) -> Int {
    let dataRange = bytes.subdata(in: offset..<(offset + length))
    return dataRange.withUnsafeBytes { $0.load(as: Int.self) }
  }
  
  private static func byteArrayToFloat(bytes: Data, offset: Int) -> Float {
    let dataRange = bytes.subdata(in: offset..<(offset + MemoryLayout<Float>.size))
    return dataRange.withUnsafeBytes { $0.load(as: Float.self) }
  }
  
}
