/*H**********************************************************************
* FILENAME : arguments.h           
*
* DESCRIPTION :
*       header file for arguments.c, define a structure called Arguments with all arguments defined inside
*
* FUNCTION prototype :
*       int validateArguments(Arguments *args, int argc, char **argv)
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

typedef struct Arguments{
	unsigned int delay;
	unsigned int brightness;
	unsigned int contrast;
	unsigned int saturation;
} Arguments;

int validateArguments(Arguments *args, int argc, char **argv);

#endif