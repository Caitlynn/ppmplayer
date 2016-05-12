#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "makeWindow.h"
#include "adjustBrightness.h"
#include "adjustContrast.h"

int makeWindow(SDL_Window **window, FILE *file, unsigned int Screen_width, unsigned int Screen_height, Arguments *arguments){
	
	if (*window == NULL) {
		*window = SDL_CreateWindow("ppm player", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Screen_width, Screen_height, SDL_WINDOW_SHOWN);
		if (*window == NULL){
			printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
	}
	
	SDL_Surface *screenSurface = NULL;
	screenSurface = SDL_GetWindowSurface(*window);
	if (screenSurface == NULL) {
		fprintf(stderr, "Couldn't get window surface! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	size_t pixels = Screen_width*Screen_height;
	for (int i = 0; i < pixels; i++){
		unsigned char colour[3];
		if (fread(colour, sizeof(unsigned char), 3, file) != 3){
			fprintf(stderr, "Couldn't read 3 colours value!\n");
			return false;
		}

		#if SDL_BYTEORDER == SDL_BIG_ENDIAN
			const int r = 0;
			const int g = 1;
			const int b = 2;
		#else
			const int r = 2;
			const int g = 1;
			const int b = 0;
		#endif

		Pixel pixel = {
			.red = colour[r],
			.green = colour[g],
			.blue = colour[b]
		};

		if (arguments->brightness != 50){
			int adjustresult = adjustBrightness(arguments->brightness, &pixel);
			if(!adjustresult){
				fprintf(stderr, "Couldn't apply brightness properly!\n");
				return false;
			}
		}

		if (arguments->contrast != 50){
			int adjustresult = adjustContrast(arguments->contrast, &pixel);
			if(!adjustresult){
				fprintf(stderr, "Couldn't apply contrast properly!\n");
				return false;
			}
		}

		// write the colour into the memory according to the byteorder
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)]  = pixel.red;
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+1]  = pixel.green;
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+2]  = pixel.blue;
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+3]  = 255;

	}	
	SDL_UpdateWindowSurface(*window); // todo catch errors

	return true;
 }
