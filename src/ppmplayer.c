#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "arguments/arguments.h"

int main(int argc, char *argv[]){
	Arguments args = {
		.delay = 0
	};

	if (!validateArguments(&args, argc, argv)){
		return false;
	}
	
	if(stdin == NULL){
		fprintf(stderr, "no ppm input!\n");
		return false;
	}

	FILE *file = fscanf(stdin) 



	return true;



}