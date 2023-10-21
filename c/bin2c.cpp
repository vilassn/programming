#include <iostream>
#include <fstream>
#include <vector>

int main() {
    const char* inputFileName = "../resources/filters_vocab_multilingual.bin";
    const char* outputFileName = "filters_vocab_multilingual.h"; 
	
	//inputFileName = "../resources/filters_vocab_gen.bin";
    //outputFileName = "filters_vocab_gen.h"; 

    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file: " << inputFileName << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file: " << outputFileName << std::endl;
        return 1;
    }

    // Write the C/C++ header
    outputFile << "#ifndef " << outputFileName << "_H" << std::endl;
    outputFile << "#define " << outputFileName << "_H" << std::endl;
    outputFile << std::endl;
    outputFile << "unsigned char " << outputFileName << "[] = {" << std::endl;

    // Read the binary data and write it to the C array
    char byte;
    bool firstByte = true;
	int break_line = 0;
    while (inputFile.read(&byte, sizeof(byte))) {
        if (!firstByte) {
            outputFile << ", ";
        }
				
		if(break_line == 12) {
			break_line = 0;
			outputFile << std::endl;
		}
		
        outputFile << '\t' << "0x" << std::hex << static_cast<int>(static_cast<unsigned char>(byte));
        firstByte = false;
		
		break_line++;
    }

    outputFile << std::endl << "};" << std::endl;
    outputFile << "unsigned int " << outputFileName << "_size = sizeof(" << outputFileName << ");" << std::endl;
    outputFile << std::endl;
    outputFile << "#endif // " << outputFileName << "_H" << std::endl;

    inputFile.close();
    outputFile.close();

    std::cout << "Binary file '" << inputFileName << "' converted to '" << outputFileName << "'" << std::endl;
    return 0;
}
