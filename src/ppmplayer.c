#include "handleFile/headerRead.h"
#include "arguments/arguments.h"
#include "handleFile/headerRead.h"
#include "handleFile/readFiles.h"
#include "ppmplayer.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc, char *argv[]){
	Arguments args = {
		.delay = 0,
		.brightness = NULL,
		.contrast = NULL,
		.saturation = NULL
	};

	if (!validateArguments(&args, argc, argv)){
		return false;
	}
	
	FILE *ppmFile;
	if (fscanf(stdin, ppmFile) == 0){
		return false;
	}

	Header ppmFileHeader = {
		.width = 0,
		.height =0
	};
	int resultHeader = headerRead(ppmFile, &ppmFileHeader);
	if (!resultHeader) {
		return false;
	}

	Frame frame = {
		.height = ppmFileHeader.height,
		.width = ppmFileHeader.width,
		.framedata = NULL
	};
	int resultFrame = readFile(ppmFile, frame);
	if (!resultFrame){
		return false;
	}

	return true;
}