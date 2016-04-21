#include <stdio.h>
#include <stdbool.h>
#include "arguments/arguments.h"

int main(int argc, char *argv[]){
	Arguments args = {
		.delay = 0
	};

	if (!validateArguments(&args, argc, argv)){
		return false;
	}
	
	if(stdin == NULL){
		fprintf(stderr, "rledecode doesn't work properly!\n");
		return false;
	}
	fprintf(args.delay, "%d\n" );
	return true;

}