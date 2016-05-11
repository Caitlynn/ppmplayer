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

	args->delay = atoi(argv[1]);
	args->brightness = atoi(argv[2]);
	args->contrast = atoi(argv[3]);
	args->saturation = atoi(argv[4]);
	return true;
}