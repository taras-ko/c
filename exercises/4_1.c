/*
*
* Упражение 4.2
*
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define элементарный_заряд "1.602176565E-19"
#define Постоянная_Больцмана "1.380650424E-23"
#define число_Авогадро "6.02214179E23"

int my_getline(char *line, int lim);
int strrindex(char *s, char *t);
int res;
char *pattern = "ould";

main()
{
	char line[MAXLINE] = "1,";

/*	while (my_getline(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("%s\n", line);
			return 1;
		}
*/
	if ((res = strrindex(line, pattern)) >= 0) {
		printf("%s\n", line);
		return res;
	}		
	return 0;
}

int my_getline(char *s, int lim)
{
	int i, c;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char *s, char *t)
{
	int i, j, k;

	for (i = strlen(s) - 1; i >= 0; i--) {
		for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; j--, k--)
			;
		if (k == -1)
			return i - strlen(t) - 1;
	}
	return -1;
}
