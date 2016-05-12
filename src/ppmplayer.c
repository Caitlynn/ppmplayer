/*H**********************************************************************
* FILENAME : ppmplayer.c   
*
* DESCRIPTION :
*       the main function of the whole program
*		ordering and calling the functions from other files and make the whole program work
*
* PUBLIC FUNCTIONS :
*       int main(int argc, char *argv[])
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#include "handleFile/headerRead.h"
#include "arguments/arguments.h"
#include "handleFile/headerRead.h"
#include "display/makeWindow.h"
#include "ppmplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]){
	Arguments args = {
		.delay = 0,
		.brightness = 0,
		.contrast = 0,
		.saturation = 0
	};

	if (!validateArguments(&args, argc, argv)){
		return 1;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL couldn't initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window *window = NULL;

	while (!feof(stdin)){
		Header ppmFileHeader = {
		.width = 0,
		.height = 0
		};
		int resultHeader = headerRead(stdin, &ppmFileHeader);
		if (!resultHeader) {
			return 1;
		}

		int resultWindow = makeWindow(&window, stdin, ppmFileHeader.width, ppmFileHeader.height, &args);
		if (!resultWindow){
			return 1;
		}
		SDL_Delay(args.delay); // wait input delay milliseconds
		//read the -1 at the end of the frame
		if (!feof(stdin)){
			int seperator;
			if (fread(&seperator, sizeof(int), 1, stdin) != 1){
				fprintf(stderr, "Couldn't read the last character\n");
				return false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();	

	return 0;
}