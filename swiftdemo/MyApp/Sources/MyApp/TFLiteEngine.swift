import Foundation

class TFLiteEngine: NSObject {
  
  let mWhisper = WhisperUtil()
  
  static func moduleName() -> String! {
    return "TFLiteEngine"
  }
  
  func initialize(vocabPath: String, isMultilingual: Bool = true) -> Bool {
      // Load filters and vocab
      guard let _ = try? mWhisper.loadFiltersAndVocab(multilingual: isMultilingual, vocabPath: vocabPath) else{
        print("Error1")
		return false
      }
	  
	  return true
  }

  func getTranscription( fileName: String, modelName: String) -> String? { 
    guard let floatArray = try? self.getMelSpectrogram(wavePath: fileName) else{
		print("Error - while creating Mel spectrogram")
		return "Error - while creating Mel spectrogram"
    }
    return ""
  }
  
  func getMelSpectrogram(wavePath: String) throws -> [Float] {
    // Get samples in PCM_FLOAT format
    let samples = WaveUtil.getSamples(from: wavePath)
    
    let fixedInputSize = WhisperUtil.WHISPER_SAMPLE_RATE * WhisperUtil.WHISPER_CHUNK_SIZE
    var inputSamples = [Float](repeating: 0.0, count: fixedInputSize)

	//print("6666666666666666:\(samples)")
	let copyLength = min(samples.count, fixedInputSize)
	if copyLength > 0 {
		inputSamples[0..<copyLength] = samples[0..<copyLength]
	}
	
	print("calculating mel spectrogram...\(Date())")
    let cores = ProcessInfo.processInfo.processorCount
    let mel = mWhisper.calculateMelSpectrogram(samples: inputSamples, nSamples: inputSamples.count, nThreads: cores)
	print("spectrogram calculation done...\(Date())")
	print("mel...\(mel.count)")
	
	return []
  }
 
}
