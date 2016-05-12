#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "adjustContrast.h"

int adjustContrast(unsigned int contrast, Pixel *pixel){
	double adjust = (double)(((double)contrast - 50) * 2) / 100 * 128;
	double f;

	//because here f can be negative or over 255 so using fmax and fmin to put the value in between
	f = (259 * (adjust + 255))/(255 * (259 - adjust));

	pixel->red = (unsigned char)fmin(fmax((f * ((double)pixel->red - 128) + 128),0),255);
	pixel->green = (unsigned char)fmin(fmax((f * ((double)pixel->green - 128) + 128),0),255);
	pixel->blue = (unsigned char)fmin(fmax((f * ((double)pixel->blue - 128) + 128),0),255);

	return true;
}