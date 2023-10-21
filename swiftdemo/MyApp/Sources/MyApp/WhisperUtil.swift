import Foundation

class WhisperUtil {
  
  // Static properties for the WhisperUtil class (similar to Companion object in Kotlin)
  static let WHISPER_SAMPLE_RATE = 16000
  static let WHISPER_N_FFT = 400
  static let WHISPER_N_MEL = 80
  static let WHISPER_HOP_LENGTH = 160
  static let WHISPER_CHUNK_SIZE = 30
  static let WHISPER_MEL_LEN = 3000
  static let golden_generated_ids = [
    50257, 50362, 1770, 13, 2264, 346, 353, 318,
    262, 46329, 286, 262, 3504, 6097, 11, 290, 356, 389, 9675, 284, 7062
  ]
  
  var vocab = WhisperVocab()
  var filters = WhisperFilter()
  var mel = WhisperMel()
  
  // Helper function definitions
  func getWordFromToken(token: Int) -> String? {
    return vocab.tokenToWord[token]
  }
  
  func readFloatArray(from filename: String, withExtension ext: String = "bin") -> [Float]? {
    guard let url = Bundle.main.url(forResource: filename, withExtension: ext) else {
      print("Failed to find \(filename).\(ext) in bundle.")
      return nil
    }
    do {
      let data = try Data(contentsOf: url)
      let count = data.count / MemoryLayout<Float>.size
      var floatArray = [Float](repeating: 0, count: count)
      let _ = floatArray.withUnsafeMutableBufferPointer { buffer in
        data.copyBytes(to: buffer)
      }
      return floatArray
    } catch let error {
      print("Failed to load \(filename).\(ext) from bundle:", error)
      return nil
    }
  }
  
  func loadInt32(from data: Data, at offset: inout Int) -> Int32 {
    let intData = data.subdata(in: offset..<(offset + MemoryLayout<Int32>.size))
    let value = intData.withUnsafeBytes { $0.load(as: Int32.self) }
    offset += MemoryLayout<Int32>.size
    return value
  }
  
  func loadFiltersAndVocab(multilingual: Bool, vocabPath: String) throws -> Bool? {
    
    do {
      // Set whether vocab is multilingual or not
      self.vocab.setMultilingual(multilingual: multilingual)
      
	  
      // Read vocab file
      guard let data = try? Data(contentsOf: URL(fileURLWithPath: vocabPath)) else {
        print("Error reading file at \(vocabPath)")
        return nil
      }
      print("Vocab file size: \(data.count)")
      
      var offset = 0
      
      // Extract the first 4 bytes and interpret them as a UInt32
      let magic: UInt32 = data.prefix(4).withUnsafeBytes { $0.load(as: UInt32.self) }
      offset += MemoryLayout<UInt32>.size
      
      
      // Convert to host byte order (assuming the file is little-endian)
      let magicHostOrder = magic.littleEndian
      
      // Check against the magic number
      if magicHostOrder == 0x5553454E {
        print("Magic number: \(magicHostOrder)")
      } else {
        print("Invalid vocab file (bad magic: \(magicHostOrder)), \(vocabPath)")
        return nil
      }
      
      // Load mel filters
      self.filters.nMel = Int(loadInt32(from: data, at: &offset))
      self.filters.nFft = Int(loadInt32(from: data, at: &offset))
      print("self.filters.nMel: \(self.filters.nMel)")
	  print("self.filters.nFft: \(self.filters.nFft)")
      
      let filterDataSize = self.filters.nMel * self.filters.nFft * MemoryLayout<Float>.size
      let filterData = [UInt8](data[offset..<(offset + filterDataSize)])
      offset += filterDataSize
      
      self.filters.data = filterData.withUnsafeBytes { Array($0.bindMemory(to: Float.self)) }
	  
    // Print the filterData values
    for value in self.filters.data {
        //print(value)
    }
      
      // Load vocabulary
      let nVocab = Int(loadInt32(from: data, at: &offset))
      
      for i in 0..<nVocab {
        let len = Int(loadInt32(from: data, at: &offset))
        let wordData = [UInt8](data[offset..<(offset + len)])
        if let word = String(bytes: wordData, encoding: .utf8) {
          self.vocab.tokenToWord[i] = word
        }
        offset += len
      }
      // Add additional vocab ids
      if self.vocab.isMultilingual() {
        self.vocab.tokenEot += 1
        self.vocab.tokenSot += 1
        self.vocab.tokenPrev += 1
        self.vocab.tokenSolm += 1
        self.vocab.tokenNot += 1
        self.vocab.tokenBeg += 1
      }
      
      for i in Int(nVocab)..<self.vocab.nVocab {
        
        let word: String
        switch i {
        case self.vocab.tokenEot:
          word = "[_EOT_]"
        case self.vocab.tokenSot:
          word = "[_SOT_]"
        case self.vocab.tokenPrev:
          word = "[_PREV_]"
        case self.vocab.tokenNot:
          word = "[_NOT_]"
        case self.vocab.tokenBeg:
          word = "[_BEG_]"
        case self.vocab.tokenBeg+1..<self.vocab.nVocab:
          word = "[_TT_\(i - self.vocab.tokenBeg)]"
        default:
          word = "[_extra_token_\(i)]"
        }
        self.vocab.tokenToWord[Int(i)] = word
      }
      return true;
    } catch let error {
      print("\(error)")
    }
  }
  
  func calculateMelSpectrogram(samples: [Float], nSamples: Int, nThreads: Int) -> [Float] {
  
	print("In calculateMelSpectrogram1...\(Date())")
    
    let fftSize = WhisperUtil.WHISPER_N_FFT
    let fftStep = WhisperUtil.WHISPER_HOP_LENGTH
    
    mel.nMel = WhisperUtil.WHISPER_N_MEL
    mel.nLen = nSamples / fftStep
    mel.data = [Float](repeating: 0.0, count: mel.nMel * mel.nLen)
	
    print("In calculateMelSpectrogram2...\(Date())")
	
    var hann = [Float](repeating: 0.0, count: fftSize)
    for i in 0..<fftSize {
      hann[i] = Float(0.5 * (1.0 - cos(2.0 * Double.pi * Double(i) / Double(fftSize))))
    }
	
    print("In calculateMelSpectrogram3...\(Date())")
	
    let nFft = 1 + fftSize / 2
    var fftIn = [Float](repeating: 0.0, count: fftSize)
    var fftOut = [Float](repeating: 0.0, count: fftSize * 2)
	
	let dateFormatter = DateFormatter()
	dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss.SSS" // Use ".SSS" to include milliseconds
	dateFormatter.locale = Locale(identifier: "en_US_POSIX") // Set locale to ensure consistency

	let currentDate = Date()
	let formattedDate = dateFormatter.string(from: Date())
	print("In calculateMelSpectrogram4...\(formattedDate)")
	
    for i in 0..<mel.nLen {
      let offset = i * fftStep
      
      // apply Hanning window
      for j in 0..<fftSize {
        if offset + j < nSamples {
          fftIn[j] = hann[j] * samples[offset + j]
        } else {
          fftIn[j] = 0.0
        }
      }
      
      // FFT -> mag^2
      fft(input: fftIn, output: &fftOut) // Assuming `fft` modifies fftOut in place
      for j in 0..<fftSize {
        fftOut[j] = fftOut[2 * j] * fftOut[2 * j] + fftOut[2 * j + 1] * fftOut[2 * j + 1]
      }
      
      for j in 0..<(fftSize / 2) {
        fftOut[j] += fftOut[fftSize - j - 1]
      }
      
      // mel spectrogram
      for j in 0..<mel.nMel {
        var sum: Float = 0.0
        for k in 0..<nFft {
          sum += fftOut[k] * filters.data[j * nFft + k]
        }
        
        if sum < 1e-10 {
          sum = 1e-10
        }
        
        sum = log10(sum)
        mel.data[j * mel.nLen + i] = sum
      }
    }
    
	let currentDate1 = Date()
	let formattedDate1 = dateFormatter.string(from: currentDate1)
	print("In calculateMelSpectrogram5...\(formattedDate1)")
	
    // clamping and normalization
    var mmax = -1e20
    for i in 0..<(mel.nMel * mel.nLen) {
      if Double(mel.data[i]) > mmax {
        mmax = Double(mel.data[i])
      }
    }
    
	print("In calculateMelSpectrogram6...\(Date())")
	
    mmax -= 8.0
    for i in 0..<(mel.nMel * mel.nLen) {
      if Double(mel.data[i]) < mmax {
        mel.data[i] = Float(mmax)
      }
      mel.data[i] = Float((Double(mel.data[i]) + 4.0) / 4.0)
    }
    
	print("In calculateMelSpectrogram7...\(Date())")
	
    return mel.data
  }
  

  private func dft(input: [Float], output: inout [Float]) {
    let inSize = input.count
    for k in 0..<inSize {
      var re: Float = 0.0
      var im: Float = 0.0
      for n in 0..<inSize {
        let angle = 2.0 * Float.pi * Float(k) * Float(n) / Float(inSize)
        re += input[n] * cos(angle)
        im -= input[n] * sin(angle)
      }
      output[k * 2] = re
      output[k * 2 + 1] = im
    }
  }
  
  private func fft(input: [Float], output: inout [Float]) {
    let inSize = input.count
    if inSize == 1 {
      output[0] = input[0]
      output[1] = 0.0
      return
    }
    
    if inSize % 2 == 1 {
      dft(input: input, output: &output)
      return
    }
    
    var even = [Float](repeating: 0.0, count: inSize / 2)
    var odd = [Float](repeating: 0.0, count: inSize / 2)
    
    var indxEven = 0
    var indxOdd = 0
    for i in 0..<inSize {
      if i % 2 == 0 {
        even[indxEven] = input[i]
        indxEven += 1
      } else {
        odd[indxOdd] = input[i]
        indxOdd += 1
      }
    }
    
    var evenFft = [Float](repeating: 0.0, count: inSize)
    var oddFft = [Float](repeating: 0.0, count: inSize)
    
    fft(input: even, output: &evenFft)
    fft(input: odd, output: &oddFft)
    for k in 0..<(inSize / 2) {
      let theta = 2.0 * Float.pi * Float(k) / Float(inSize)
      let re = cos(theta)
      let im = -sin(theta)
      let reOdd = oddFft[2 * k]
      let imOdd = oddFft[2 * k + 1]
      output[2 * k] = evenFft[2 * k] + re * reOdd - im * imOdd
      output[2 * k + 1] = evenFft[2 * k + 1] + re * imOdd + im * reOdd
      output[2 * (k + inSize / 2)] = evenFft[2 * k] - re * reOdd + im * imOdd
      output[2 * (k + inSize / 2) + 1] = evenFft[2 * k + 1] - re * imOdd - im * reOdd
    }
  }
}


// Helper class definitions

class WhisperVocab {
  // Token types
  var tokenEot = 50256 // end of transcript
  var tokenSot = 50257 // start of transcript
  var tokenPrev = 50360
  var tokenSolm = 50361 // ??
  var tokenNot = 50362 // no timestamps
  var tokenBeg = 50363
  
  let tokenTranslate = 50358
  let tokenTranscribe = 50359
  
  var tokenToWord: [Int: String] = [:]
  
  // Vocab types
  let nVocabMultilingual = 51865    // for multilingual vocab
  let nVocabNonMultilingual = 51864 // for non-multilingual vocab
  
  // Initialize nVocab as default types
  var nVocab = 51865
  
  func setMultilingual(multilingual: Bool) {
    nVocab = multilingual ? nVocabMultilingual : nVocabNonMultilingual
  }
  
  func isMultilingual() -> Bool {
    return nVocab == nVocabMultilingual
  }
}

class WhisperFilter {
  var nMel = 0
  var nFft = 0
  var data: [Float] = []
}

class WhisperMel {
  var nLen = 0
  var nMel = 0
  var data: [Float] = []
}

class InputLang {
  var name: String
  var code: String
  var id: Int64
  
  init(name: String, code: String, id: Int64) {
    self.name = name
    self.code = code
    self.id = id
  }
  
  func getLangList() -> [InputLang] {
    return [
      InputLang(name: "English", code: "en", id: 50259),
      InputLang(name: "Spanish", code: "es", id: 50262),
      InputLang(name: "Hindi", code: "hi", id: 50276),
      InputLang(name: "Telugu", code: "te", id: 50299)
    ]
  }
}
