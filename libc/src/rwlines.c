#include <stdio.h>
#include <rwlines.h>
#include <_string.h>
#include <_ctype.h>

int _getline(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p;
	const char cline[MAXLEN] = "bla-bla";
	char dst[MAXLEN];
	nlines = 0;
	while ((len = _getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			p = alloc(_strlen(cline));
			_strcpy(p, line);
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

