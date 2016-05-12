#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adjustContrast.h"

int adjustContrast(unsigned int contrast, Pixel *pixel){
	unsigned int adjust = contrast - 50;
	// printf("%d\n", adjust);
	float f;
	f = (259 * ((float)adjust + 255))/(255 * (259 - (float)adjust));
	printf("%e\n", f);
	// printf("original pixel: %d %d %d\n", pixel->red, pixel->green, pixel->blue);
	pixel->red = f * ((float)pixel->red - 128) + 128;
	pixel->green = f * ((float)pixel->green - 128) + 128;
	pixel->blue = f * ((float)pixel->blue - 128) + 128;
	// printf("adjusted pixel: %d %d %d\n", pixel->red, pixel->green, pixel->blue);

	if(pixel->red < 0){
		pixel->red = 0;
	} else if(pixel->red >255){
		pixel->red = 255;
	}

	if(pixel->green < 0){
		pixel->green = 0;
	} else if(pixel->green >255){
		pixel->green = 255;
	}

	if(pixel->blue < 0){
		pixel->blue = 0;
	} else if(pixel->blue >255){
		pixel->blue = 255;
	}


	return true;
}