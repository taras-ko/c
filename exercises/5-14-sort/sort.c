#include <stdio.h>
#include <rwlines.h>
#include <stringlocal.h>

#define PROG "sort"

char *lineptr[MAXLINES];

char *alloc(int);
void *afree(char *);

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
		int (*comp) (void *, void *), int order);
int numcmp(char *, char *);

main(int argc, char *argv[])
{
	int nlines;      /* number of read lines */
	int ignorecase, reverse, numeric; /* 1, if numerical comparison */
	ignorecase = reverse = numeric = 0;
	char c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0]) {
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				case 'i':
					ignorecase = 1;
					break;
				case 'h':
					printf("Usage: "PROG" [-nird] \"STDIN\"\n");
					return 0;
					break;
				default:
					printf(PROG": illegal option %c\n", c);
					argc = 0;
					return 1;
					break;
			}
			if (c == '\0')
				break;
		}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		printf("\nBefore sort:\n");
		writelines(lineptr, nlines);
		int (*pf) (const char *, const char *) = ignorecase ? _strcasecmp : _strcmp;
		qsort((void **) lineptr, 0, nlines - 1,
			(int (*)(void *, void *))(numeric ? numcmp : pf), reverse);
		printf("\nAfter sort:\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too bit to sort\n");
		return 1;
	}

}
