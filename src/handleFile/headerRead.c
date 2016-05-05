#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headerRead.h"

int headerRead(FILE *ppmFile, Header *header){
	if (feof(ppmFile)){
		return false;
	} else {
		if (fscanf(ppmFile, "P6\n%d %d\n255\n", &(header->width), &(header-> height)) != 2){
			fprintf(stderr, "couldn't read the header\n");
			return false;
		}
	}

	if (header->width < 1 || header->height < 1){
		fprintf(stderr, "the width and height values are incorrect\n");
		return false;
	}
	return true;
}