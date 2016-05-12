/*H**********************************************************************
* FILENAME : adjustBrightness.c    
*
* DESCRIPTION :
*       apply adjustment to the input pixel according to the input brightness requirement
*
* PUBLIC FUNCTIONS :
*       int adjustBrightness(unsigned int brightness, Pixel *pixel)
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "adjustBrightness.h"

int adjustBrightness(unsigned int brightness, Pixel *pixel){
	double adjust = (double)brightness/50;

	pixel->red = (unsigned char)fmin((double)pixel->red * adjust, 255);
	pixel->green = (unsigned char)fmin((double)pixel->green * adjust, 255);
	pixel->blue = (unsigned char)fmin((double)pixel->blue * adjust, 255);

	return true;
}