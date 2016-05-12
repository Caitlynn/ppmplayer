/*H**********************************************************************
* FILENAME : headerRead.h   
*
* DESCRIPTION :
*       header file for headerRead.c, and defines a struct Header with width and height
*
* FUNCTION prototype :
* 		int headerRead(SDL_Window **window, FILE *file, unsigned int Screen_width, unsigned int Screen_height, Arguments *args);
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#ifndef HEADERREAD_H
#define HEADERREAD_H
#include <stdio.h>

typedef struct Header{
	int width;
	int height;
} Header;

int headerRead(FILE *ppmFile, Header *header);
#endif