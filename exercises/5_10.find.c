#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
//
int getline_(char *line, int max);
char *strstr_(char *s, char *t);

/* find: вывод строк содержащих образец из последнего аргумента; */
main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;	
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);		
					argc = 0;
					found = - 1;
					break;
			}
	if (argc != 1)
		printf ("Usage: find -x -n pattern\n");
	else 
		while (getline_(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr_(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
					printf("%s", line);
					found++;
			}
		}
	return found;
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
