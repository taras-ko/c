#include <stdio.h>

#define MAXOP 100
static double stack[MAXOP];
static double *ps = stack; 

void push(double arg)
{
	if (ps <= stack + MAXOP)
		*ps++ = arg;
	else 
		printf("error: operands stack overflow\n");
}

double pop(void)
{
	if (ps < stack) {
		printf("warning: stack is empty\n");
		return 0.0; 
	}

	return *--ps;
}
