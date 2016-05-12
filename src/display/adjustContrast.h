/*H**********************************************************************
* FILENAME : adjustContrast.h   
*
* DESCRIPTION :
*       header file for adjustContrast.c
*
* FUNCTION prototype :
* 		int adjustContrast(unsigned int contrast, Pixel *pixel);
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/

#ifndef CONTRAST_H
#define CONTRAST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "makeWindow.h"

int adjustContrast(unsigned int Contrast, Pixel *pixel);

#endif