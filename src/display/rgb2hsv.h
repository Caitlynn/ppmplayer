#ifndef RGB2HSV_H
#define RGB2HSV_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hsv2rgb.h"

typedef struct RgbColour{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RgbColour;

HsvColour rgb2hsv(RgbColour rgb);

#endif