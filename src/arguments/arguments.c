#include "arguments.h"
#include <stdio.h>
#include <stdbool.h>

int validateArguments(Arguments *args, int argc, char **argv){
	/*validate the number of the arguments*/
	if (argc < 1){
		fprintf(stderr, "Please enter correct arguments!\n");
		return false;
	}

	args->delay = argv[1];

}