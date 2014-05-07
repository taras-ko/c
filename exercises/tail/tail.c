#include <stdio.h>
#include <string.h>

#include "tail.h"
#define MAXLINES 5000  /* max number of read lines */
#define DEFAULT_TAIL_LINES 10   /* number of lines to print from tail */

char *lineptr[MAXLINES]; /* pointers to strings */
int nlines = 0;

int _getline(char *, int);

char *alloc(int);
void *afree(char *);

void push(char *line)
{
	extern nlines;
	extern char *lineptr[];

	/* Allocate memory for current line, aquire pointer */
	char *p;
	p = alloc(strlen(line) + 1); /*its for terminating '\0' sym */
	strcpy(p, line);
	*(p + strlen(line) + 1) = '\0';

	/* Shift all pointers to the right */
	int top = 0;
	int bottom = nlines - 1, bob = bottom;
	afree(lineptr[bob]);
	for (; bob > 0; bob--)
		lineptr[bob] = lineptr[bob - 1];

	/* place on top current line */
	lineptr[top] = p;
}

main(int argc, char *argv[])
{
	char line[MAXLEN];
	long lineno = 0;
	int c, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0]) {
			switch (c) {
				case 'n':
					c = *++argv[0];
					while (c != '\0' && isdigit(c))
					{
						nlines = nlines * 10 + (c - '0');
						c = *++argv[0];
					}
					break;
				case 'h':
					printf("Usage: tail -n<number> \"input text...\"\n");
					break;
				default:
					printf("tail: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
			if (c == '\0')
				break;
		}

	extern nlines;
	if (nlines == 0)
		nlines = DEFAULT_TAIL_LINES;

	while (_getline(line, MAXLEN) > 0)
	{
		push(line);
	}

	extern char *lineptr[];
	extern int stack_bottom;
	int i;
	for (i = nlines - 1; i >= 0; i--)
		printf("%s", lineptr[i]);
}

