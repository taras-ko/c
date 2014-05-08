#include <stdio.h>
#include <errno.h>

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
	char c;
	c = fgetc(stream);
	if (isspace(c))
		return space;
	switch (c) {
		case '#':
			return directive;
		case '"':
			return string_constant;
		case '/':
			c = fgetc(stream);
			if (c == '/')
				return oneline_comment;
			if (c == '*')
				return multiline_comment;
		default:
			ungetc(c, stream);
			return word;
	}
}

static void skip_token(TokenType tok)
{
	if (tok == word)
		return;

	char c;
	while ((c = fgetc(stream)) != EOF)
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
				char next_c;
				if (c == '*' && (next_c = fgetc(stream)) == '/')
					goto _exit;
				else
					ungetc(next_c, stream);
				break;
			}
		}

_exit:
	if (c == EOF)
		ungetc(c, stream);
}

/* Reads next word or sym from file stream */
int getword(char *word, int lim)
{
	skip_token(detect_token());

	char c;
	while (!isspace(c = fgetc(stream)) && lim > 0 && c != EOF)
		if (isalnum(c) || c == '(') {
			*word++ = c;
			lim--;
		}

	*word = '\0';

	return (c != EOF) ? 1 : 0;
}

/* determine if word is c function */
int isfunc(char *word)
{
	char *p = word;
	for ( ; *p != '\0'; p++)
		if (*p == '(')
			return 1;
	return 0;
}

