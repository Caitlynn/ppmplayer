#ifndef HEADERREAD_H
#define HEADERREAD_H
#include <stdio.h>
#include "../ppmplayer.h"

typedef struct Header{
	int width;
	int height;
} Header;

int headerRead(FILE *ppmFile, Header *header);
#endif