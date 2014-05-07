#include <stdlib.h>

int _strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}

void _strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

char *_strdup(char *s)
{
	char *p;

	p = (char *) malloc(_strlen(s) + 1);
	if (p != NULL)
		_strcpy(p, s);
	return p;
}

int _strcmp(const char *s1, const char *s2)
{
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

int _strncmp(const char *s1, const char *s2, int n)
{
	for ( ; n > 0 && *s1 == *s2; s1++, s2++, n++)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

int _strcasecmp(const char *s1, const char *s2)
{
	for ( ; lower(*s1) == lower(*s2); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

char *_strcat(char *s1, const char *s2)
{
	while (*s1++ != '\0')
		;
	s1--;
	while ((*s1++ = *s2++) != '\0')
		;
	*s1 = '\0';

	return s1;
}
