#include <stdio.h>
#include <_string.h>
#include <rwlines.h>

char s1[MAXLEN], s2[MAXLEN];

main(int argc, char *argv[])
{
	printf("_strcat(s1, s2) test\n");

	printf("\tinput s1: ");
	_getline(s1, MAXLEN);

	printf("\tinput s2: ");
	_getline(s2, MAXLEN);

	_strcat(s1, s2);
	printf("output: %s\n", s1);

	return 0;
}
