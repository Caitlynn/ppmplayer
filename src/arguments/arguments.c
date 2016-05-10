#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include "arguments.h"


int validateArguments(Arguments *args, int argc, char **argv){
	/*validate the number of the arguments*/
	if (argc < 1){
		fprintf(stderr, "Please enter correct arguments!\n");
		return false;
	} 

	args->delay = (unsigned int)argv[1];

	const struct option long_options[] = {
		{ "brightness", 1, NULL, 'b'},
		{ "contrast", 1, NULL, 'c'},
		{ "saturation", 1, NULL, 's'}
	};
	int indexptr;
	int arg;

	while((arg = getopt_long(argc, argv, "b:c:s", long_options, &indexptr)) != -1){
		switch(arg){
			case 'b':
				args->brightness = atoi(optarg);
				break;
			case 'c':
				args->contrast = atoi(optarg);
				break;
			case 's':
				args->saturation = atoi(optarg);
				break;
		}
	}
	return true;
}