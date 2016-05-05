#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "readFiles.h"


int readFiles(FILE *file, Frame *frame){
	size_t size = frame->height * frame->width * 3;
	frame->framedata = malloc(sizeof(unsigned char) * size);
	size_t i = 0;

	//put the data into a fram structure
	while (i < size){
		char character = fgetc(file);
		if (character == EOF){
			fprintf(stderr, "unexpected eof\n");
			return false;
		}
		frame -> framedata[i] = character;
		i++;
	}
	
	//read the '-1' at the end of the ppm file
	int seperator;
	fread(seperator, sizeof(int), 1, file);

	if (seperator == EOF){
		fprintf(stderr, "unexpected eof\n");
		return false;
	}

	if (seperator != -1){
		fprintf(stderr, "the ppm file didn't end with '-1'\n");
		return false;
	}
	return true;


	
}