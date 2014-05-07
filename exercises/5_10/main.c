#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "expr.h"

#define MAXLINE 1000
int getline_(char *line, int max);
char *strstr_(char *s, char *t);

/* expr 2 3 4 + * */
main(int argc, char *argv[])
{
	int type;

	while (--argc > 0 && *++argv != NULL)
		switch (type = argeval(*argv)) {
			case NUMBER:
				push(atof(*argv));
				break;
			case '+':
				push(pop() + pop());
				break;
			case ERROP: 
				;
			default:
				printf("error: unknown symbol %s\n", *argv);
				return -1;
				break;
		}
	printf("%f\n", pop());
	return 0;
}

char *strstr_(char *s, char *t)
{
	char *r;	
	int u;

	for (; *s; s++) {
		for (r = s, u = 0; *(t + u) != '\0' && *r == *(t + u); r++, u++)
			;
		if (u > 0 && *(t + u) == '\0')
			return s;
	}
	return NULL;
}

int getline_(char *s, int lim)
{
	int c;
	char *p = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - p;
}
