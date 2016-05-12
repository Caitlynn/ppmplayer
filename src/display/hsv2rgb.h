#ifndef HSV2RGB_H
#define HSV2RGB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rgb2hsv.h"

typedef struct HsvColour{
	unsigned char h;
	unsigned char s;
	unsigned char v;
} HsvColour;

RgbColour hsv2rgb(HsvColour hsv);
#endif