/*H**********************************************************************
* FILENAME : makeWindow.h   
*
* DESCRIPTION :
*       header file for makeWindow.c, and defines a struct Pixel with red green blue inside.
*
* FUNCTION prototype :
* 		int makeWindow(SDL_Window **window, FILE *file, unsigned int Screen_width, unsigned int Screen_height, Arguments *args);
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#ifndef MAKEWINDOW_H
#define MAKEWINDOW_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../arguments/arguments.h"


typedef struct Pixel{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Pixel;

int makeWindow(SDL_Window **window, FILE *file, unsigned int Screen_width, unsigned int Screen_height, Arguments *args);


#endif