#include <stdio.h>
#include <stdlib.h>
unsigned char byte;

int main(int argc, char** argv) {

	if (argc != 3) {
		printf("Usage: corrupt_file_copier source_file destination_file\n");
		exit(1);
	}

	FILE *fin, *fout;
	int val;
	fin = fopen(argv[1], "rb");
	if (fin == NULL) {
		printf("Error opening input file\n");
		exit(1);
	}

	fout = fopen(argv[2], "wb");
	if (fout == NULL) {
		printf("Error opening output file\n");
		exit(1);
	}
	printf("Files opened, copying beginning.\n");

	fseek(fin, 0, SEEK_END);
	int size = ftell(fin);
	printf("File size: %d bytes\n", size);
	fseek(fin, 0, SEEK_SET);

	while (1) { //infinant loop
		val = fgetc(fin);

		if (val == EOF) {
			off_t offset = ftell(fin);
			printf("eof encountered at Offset: %d\n", offset);
			offset = offset + 1;
			fseek(fin, offset, SEEK_SET);
			if (offset <= size)
				continue;
			else
				break;
		}

		byte = (unsigned char) val;
		fputc(byte, fout);
	}

	printf("Copy successful!\n");
}
