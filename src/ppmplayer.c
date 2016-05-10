#include "handleFile/headerRead.h"
#include "arguments/arguments.h"
#include "handleFile/headerRead.h"
#include "display/makeWindow.h"
#include "ppmplayer.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc, char *argv[]){
	Arguments args = {
		.delay = 0,
		.brightness = 0,
		.contrast = 0,
		.saturation = 0
	};

	if (!validateArguments(&args, argc, argv)){
		return false;
	}

	Header ppmFileHeader = {
		.width = 0,
		.height = 0
	};
	int resultHeader = headerRead(stdin, &ppmFileHeader);
	if (!resultHeader) {
		return false;
	}

	int resultWindow = makeWindow(stdin, ppmFileHeader.width, ppmFileHeader.height, args.delay);
	if (!resultWindow){
		return false;
	}

	return true;
}