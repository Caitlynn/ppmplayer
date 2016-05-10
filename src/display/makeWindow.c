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
		window = SDL_CreateWindow("new window", 
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
			//@todo: catch error
			fread(colour, sizeof(unsigned char), 3, file);
			((Uint32 *)(screenSurface->pixels))[i]  = colour[0];
			((Uint32 *)(screenSurface->pixels))[i+1]  = colour[1];
			((Uint32 *)(screenSurface->pixels))[i+2]  = colour[2];
			//@todo: catch errors
			SDL_MapRGBA(screenSurface->format, ((Uint32 *)(screenSurface->pixels))[i], ((Uint32 *)(screenSurface->pixels))[i+1], ((Uint32 *)(screenSurface->pixels))[i+2], 255);
		}
			SDL_UpdateWindowSurface(window);
			SDL_Delay(delay);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return true;

 }
