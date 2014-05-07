/* Напишите функцию any(s1, s2), возвращающую номер первой позиции в строке s1,
 	в которой находится какой-либо из символов строки s2, либо -1, если строка s1
 	не содержит ни одного символа из s2. */
#include <stdio.h>

#define MAXLINE 255

int any(char s1[], char s2[]);
int gepline(char s[], int lim);

main()
{
	char s1[MAXLINE], s2[MAXLINE];

	do	
		printf("s1:\n");
	while (gepline(s1, MAXLINE) == 0);

	do
		printf("s2:\n");
	while (gepline(s2, MAXLINE) == 0);
	
	printf("result: %d\n", any(s1, s2));

	return 0;
}

int any(char s1[], char s2[])
{
	int i, j, exit;

	exit = i = 0;
	while (!exit && s2[i] != '\0') {
		j = 0;
		while (!exit && s1[j] != '\0') {
			if (s1[j] != '\n' && s2[i] == s1[j]) 
				exit = 1;
			++j;
		}
		++i;
	}
	if (exit)
		return j;
	else 
		return -1;	
}

int gepline(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i) 
		s[i] = c;
	if (c == '\n')	
		s[i++] = c;

	s[i] = '\0';
	
	return i;
}
