#include  <stdio.h>

#define MAXVAL 100 /* max size of stack */

int sp = 0; /* next free stack place */
double val[MAXVAL]; /* stack of operands */

/* push the number to the stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pops the toppest number from the stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
