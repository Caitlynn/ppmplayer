/*H**********************************************************************
* FILENAME : arguments.c            
*
* DESCRIPTION :
*       validate the input arguments
*
* PUBLIC FUNCTIONS :
*       int validateArguments(Arguments *args, int argc, char **argv)
* 
* AUTHOR :    Caitlynn Zhou        START DATE :    20 April 2016
*
*H*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include "arguments.h"

int validateArguments(Arguments *args, int argc, char **argv){
	/*validate the number of the arguments*/
	//@todo: argc should less than 7
	if (argc != 5){
		fprintf(stderr, "Please enter correct arguments!\n");
		return false;
	} 

	if (!(args->delay = atoi(argv[1]))){
		fprintf(stderr, "Couldn't convert the delay value to integer\n");
		return false;
	}

	if (!(args->brightness = atoi(argv[2]))){
		fprintf(stderr, "Couldn't convert the brightness value to integer\n");
		return false;
	}

	if (!(args->contrast = atoi(argv[3]))){
		fprintf(stderr, "Couldn't convert the contrast value to integer\n");
		return false;
	}

	if (!(args->saturation = atoi(argv[4]))){
		fprintf(stderr, "Couldn't convert the saturation value to integer\n");
		return false;
	}
	return true;
}