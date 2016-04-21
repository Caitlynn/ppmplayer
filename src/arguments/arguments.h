#ifndef ARGUMENTS_H
#define ARGUMENTS_H

typedef struct Arguments{
	int delay;
} Arguments;

int validateArguments(Arguments *args, int argc, char **argv);


#endif