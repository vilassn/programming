import Foundation

func main() {
    print("In main function")

	let currentFileURL = URL(fileURLWithPath: #file)
	let resourcesDirectory = currentFileURL.deletingLastPathComponent().appendingPathComponent("Resources", isDirectory: true)
	
    let engine = TFLiteEngine()
    let isMultilingual = false

    // Load the TFLite model and vocabulary
    var modelPath = resourcesDirectory.appendingPathComponent("whisper-tiny-en.tflite").path
    if isMultilingual {
        modelPath = resourcesDirectory.appendingPathComponent("whisper-tiny.tflite").path
    }

	var vocabPath = resourcesDirectory.appendingPathComponent("filters_vocab_multilingual.bin").path
	if isMultilingual {
        vocabPath = resourcesDirectory.appendingPathComponent("filters_vocab_gen.bin").path
    }
	  
    let result = engine.initialize(vocabPath: vocabPath, isMultilingual: isMultilingual)
    if result != true {
        print("Error loading the TFLite model or vocabulary.")
        exit(1)
    }

	let audioFilePath = resourcesDirectory.appendingPathComponent("jfk.wav").path
	if FileManager.default.fileExists(atPath: audioFilePath) {
		print("Audio file found: \(audioFilePath)")
		// Use audioFilePath as the path to your WAV file
	} else {
		print("Audio file not found: \(audioFilePath)")
	}

    if let transcription = engine.getTranscription(fileName: audioFilePath, modelName: modelPath) {
        print("Transcription: \(transcription)")
    } else {
        print("Error transcribing the audio file.")
        exit(2)
    }
}

// Call the main function
main()
