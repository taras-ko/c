#include <stdio.h>

/* char to integer */
int ctoi(int c)
{
	return '0' - c;
}

int _atoi(char *s)
{
	int a = 0;
	for (a = 0; *s != '\0'; s++)
		a = a * 10 + *s - '0';

	return a;
}
