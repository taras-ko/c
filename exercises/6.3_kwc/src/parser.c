#include <stdio.h>
#include <errno.h>
#include <wchar.h>

extern FILE *stream;

typedef enum {
	word,
	space,
	oneline_comment,
	multiline_comment,
	directive,
	string_constant,
} TokenType;

static TokenType detect_token()
{
	wint_t c;
	c = fgetwc(stream);
	if (isspace(c))
		return space;
	switch (c) {
		case '#':
			return directive;
		case '"':
			return string_constant;
		case '/':
			c = fgetwc(stream);
			if (c == '/')
				return oneline_comment;
			if (c == '*')
				return multiline_comment;
		default:
			ungetwc(c, stream);
			return word;
	}
}

static void skip_token(TokenType tok)
{
	if (tok == word)
		return;

	wint_t c;
	while ((c = fgetwc(stream)) != EOF)
		switch (tok) {
			case directive:
			case oneline_comment:
				if (c == '\n')
					goto _exit;
				break;
			case string_constant:
				if (c == '"')
					goto _exit;
				break;
			case multiline_comment: {
				wint_t next_c;
				if (c == '*' && (next_c = fgetwc(stream)) == '/')
					goto _exit;
				else
					ungetwc(next_c, stream);
				break;
			}
		}

_exit:
	if (c == EOF)
		ungetwc(c, stream);
}

/* Reads next word or sym from file stream */
int getword(wint_t *word, int lim)
{
	//skip_token(detect_token());

	wint_t c;
	while (iswblank(c = fgetwc(stream)) && c != EOF)
		;
	while (!iswblank(c = fgetwc(stream)) && lim > 0 && c != EOF) {
#if 0
		if (iswalnum(c) || c == '(') {
#endif
			*word++ = c;
			lim--;
		}

	*word = '\0';

	return (c != EOF) ? 1 : 0;
}

/* determine if word is c function */
int isfunc(wint_t *word)
{
	wint_t *p = word;
	for ( ; *p != '\0'; p++)
		if (*p == '(')
			return 1;
	return 0;
}

