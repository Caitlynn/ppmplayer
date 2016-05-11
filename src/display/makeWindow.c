#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "makeWindow.h"

int makeWindow(SDL_Window **window, FILE *file, unsigned int Screen_width, unsigned int Screen_height){
	
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

		// write the colour into the memory according to the byteorder
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)]  = colour[r];
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+1]  = colour[g];
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+2]  = colour[b];
		((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+3]  = 255;

	}
	SDL_UpdateWindowSurface(*window); // todo catch errors

	return true;
 }
