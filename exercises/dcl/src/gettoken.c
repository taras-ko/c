#include <mystdio.h>
#include <dcl.h>

int gettoken(void) /* return next token */
{
	extern char token[];
	extern int tokentype;

	char *p = token;
	int c;

	while (_isspace(c = getch()))
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			_strcpy(token, "()");
			return tokentype = PARENS;
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (_isalpha(c)) {
		for (*p++ = c; _isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		if (_isspace(c))
			ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}
