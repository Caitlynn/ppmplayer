#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "makeWindow.h"

int makeWindow(FILE *file, unsigned int Screen_width, unsigned int Screen_height, unsigned int delay){
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL couldn't initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("ppm player", 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			Screen_width, Screen_height, SDL_WINDOW_SHOWN);
		}

		if (window == NULL){
			printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		
		screenSurface = SDL_GetWindowSurface(window);
				 	

		size_t pixels = Screen_width*Screen_height;
		for (int i=0; i<pixels; i++){
			unsigned char colour[3];
			if (fread(colour, sizeof(unsigned char), 3, file) != 3){
				fprintf(stderr, "Couldn't read 3 colours value!\n");
				return false;
			}
			((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)]  = colour[2];
			((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+1]  = colour[1];
			((unsigned char *)(screenSurface->pixels))[i*sizeof(Uint32)+2]  = colour[0];
			// Uint32 returnpixel = SDL_MapRGB(screenSurface->format, colour[0], colour[1], colour[2]);
			// if (!returnpixel){
			// 	fprintf(stderr, "Couldn't map the colours to screen surface correctly!\n");
			// }
		}
			SDL_UpdateWindowSurface(window);
			SDL_Delay(delay);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return true;

 }
