/*H**********************************************************************
* FILENAME : adjustSaturation.c    
*
* DESCRIPTION :
*       apply adjustment to the input pixel according to the input saturation requirement
*
* PUBLIC FUNCTIONS :
*       int adjustSaturation(unsigned int saturation, Pixel *pixel)
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "adjustSaturation.h"

#define Pr .299
#define Pg .587
#define Pb .114

int adjustSaturation(unsigned int saturation, Pixel *pixel){
	double adjust = (double)((double)saturation/50);
	double p = sqrt((double)(pixel->red) * (double)(pixel->red) * Pr + (double)(pixel->green) * (double)(pixel->green) * Pg + (double)(pixel->blue) * (double)(pixel->blue) * Pb ) ;


	pixel->red = (unsigned char)fmin(fmax(p + ((double)(pixel->red) - p) * adjust,0),255);
	pixel->green = (unsigned char)fmin(fmax(p + ((double)(pixel->green) - p) * adjust,0),255);
	pixel->blue = (unsigned char)fmin(fmax(p + ((double)(pixel->blue) - p) * adjust,0),255);

	return true;
}