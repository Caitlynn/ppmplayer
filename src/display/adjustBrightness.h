/*H**********************************************************************
* FILENAME : adjustBrightness.h   
*
* DESCRIPTION :
*       header file for adjustBrightness.c
*
* FUNCTION prototype :
* 		int adjustBrightness(unsigned int brightness, Pixel *pixel);
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "makeWindow.h"

int adjustBrightness(unsigned int brightness, Pixel *pixel);

#endif