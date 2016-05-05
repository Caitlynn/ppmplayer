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