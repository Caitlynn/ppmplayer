#ifndef HSVRGB_H
#define HSVRGB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct HsvColour{
	unsigned char h;
	unsigned char s;
	unsigned char v;
} HsvColour;

typedef struct RgbColour{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RgbColour;

#endif