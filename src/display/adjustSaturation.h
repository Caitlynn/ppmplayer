/*H**********************************************************************
* FILENAME : adjustSaturation.h   
*
* DESCRIPTION :
*       header file for adjustSaturation.c
*
* FUNCTION prototype :
* 		int adjustSaturation(unsigned int saturation, Pixel *pixel);
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/
#ifndef SATURATION_H
#define SATURATION_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "makeWindow.h"

int adjustSaturation(unsigned int Saturation, Pixel *pixel);

#endif