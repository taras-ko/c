/* сортирует массив строк */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], char *pBUF, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);


/* sort input lines */
main()
{
	char BUF[MAXLINES * MAXLEN];
	char *pBUF = BUF;
	int nlines;

	/* number of input lines read */
	if ((nlines = readlines(lineptr, pBUF, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

int getline2(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *p, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	nlines = 0;
	while ((len = getline2(line, MAXLEN)) > 0 )
		if (nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len; //offseting pointer to BUF
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return;
	/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
			swap(v, left, last);
			qsort(v, left, last-1);
			qsort(v, last+1, right);
}

int getline2(char *s, int lim)
{
	int c;
	char *t = s;

	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;

	if (c == '\n') 
		*s++ = c;

	*s = '\0';

	return s - t;
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
