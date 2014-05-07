#include <stdio.h>

#include <mystdio.h>
#include <ctypelocal.h>
#include <stringlocal.h>

#include <tblfun.h>

#define MAXWORD 100

char name[MAXWORD];
char val[MAXWORD];
struct defn d = {
	name,
	val,
};

main()
{
	extern struct defn d;
	char w[MAXWORD];
	int c;

	while (getword(w) != EOF)
		if (_strcmp("#define", w) == 0) {
			getword(d.name);
			getword(d.val);
			install(&d);
		}

	undef("F");
	lookup("IN");
	lookup("OUT");
	lookup("A");
	lookup("B");
	lookup("C");
	lookup("D");
	lookup("E");
	lookup("F");
}

/* copies 1 word from stdin to the s */
int getword(char *w)
{
	int c;
	while (_isspace(c = getch()))
		;
	*w++ = c;
	while ((c = getch()) != EOF && !_isspace(c))
		*w++ = c;
	*w = '\0';
	return c;
}
