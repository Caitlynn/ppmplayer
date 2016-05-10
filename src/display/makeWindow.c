#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "makeWindow.h"

int makeWindow(FILE *file, unsigned int Screen_width, unsigned int Screen_height, unsigned int delay){
	int *p;
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;
	// const int bitdepth = 8; // 8 bits per channel
	// const int channels = 4; // R,G,B,opacity
	// // const int depth = bitdepth * channels; // 32 bits per pixel
	// Uint32 rmask,gmask,bmask,omask;
	// #if SDL_BYTEORDER == SDL_BIG_ENDIAN
	// 	rmask = 0xff000000;
	// 	gmask = 0x00ff0000;
	// 	bmask = 0x0000ff00;
	// 	omask = 0x000000ff;
	// #else
	// 	rmask = 0x000000ff;
	// 	gmask = 0x0000ff00;
	// 	bmask = 0x00ff0000;
	// 	omask = 0xff000000;
	// #endif

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL couldn't initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("new window", 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			Screen_width, Screen_height, SDL_WINDOW_SHOWN);

		if (window == NULL){
			printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGBA(screenSurface->format, 0xff, 0xff, 0xff,0xff));
		 	

			int pixels = Screen_width*Screen_height;
			Uint8 red, green, blue;
			for (size_t i = 0; i < pixels; i++){
				char c = fgetc(file);
				red = ((c >>16) & 0xFF);
				green = ((c >>8) & 0xFF);
				blue = ((c)&0xFF);
				p = screenSurface->pixels + Screen_height * screenSurface->pitch + Screen_width *screenSurface->format->BytesPerPixel;

				*p = SDL_MapRGBA(screenSurface->format, red, green, blue, 255);
			}
			
			SDL_UpdateWindowSurface(window);
			SDL_Delay(delay);
		}

		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return true;
 }
