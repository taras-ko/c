/* kwc i. e. keyword counter */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLINELEN 1000    /* maximum line length */
#define NKEYS (sizeof keytab / sizeof(struct key))

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct key {
	char *typename;
} keytab [] = {
	"char",
	"double",
	"float",
	"int",
	"long",
	"void"
};

/* ignore symbols */
char ignorestr[] = "_;,";

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *p);
int getword(char *, int);
int iscfunc(char *w);

int binsearch(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	while (low < high) {
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->typename)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return 1;
	}
	return 0;
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL && (p = talloc())) {
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

typedef enum {
	valuable_elem,
	space,
	oneline_comment,
	multiline_comment,
	directive,
	string_constant,
} TokenType;

TokenType detect_token()
{
	char c;
	c = getchar();
	switch (c) {
		case '#':
			return directive;
		case '"':
			return string_constant;
		case '/':
			c = getchar();
			if (c == '/')
				return oneline_comment;
			if (c == '*')
				return multiline_comment;
		default:
			ungetc(c, stdin);
			return valuable_elem;
	}
}

void skip_token(TokenType tok)
{
	char c;
	while ((c = getchar()) != EOF)
		switch (tok) {
			case directive:
			case oneline_comment:
				if (c == '\n')
					break;
				else
					continue;
			case string_constant:
				if (c == '"')
					break;
				else
					continue;
			case multiline_comment: {
				char next_c;
				if (c == '*' && (next_c = getchar()) == '/')
					break;
				else
					ungetc(next_c, stdin);
					continue;
			case valuable_elem:
			default:
				if (isspace(c))
					continue;
				break;
			}
		}

	if (c == EOF || tok == valuable_elem)
		ungetc(c, stdin);
}

/* Reads next word or sym from stdin */
int getword(char *word, int lim)
{
	skip_token(detect_token());

	char c;
	while (!isspace(c = getchar()) && lim > 0 && c != EOF)
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

/* Count C language keywords in a file */
int main(int argc, char *argv[])
{
	char c;
	int n;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0]) {
			switch (c) {
				case 'h':
					printf("Usage: kwc [-h][-number] \"input text...\"\n");
					break;
				default:
					if (isdigit(c))
						n = c - '0';
					else {
						printf("kwc: illegal option %c\n", c);
						argc = 0;
					}
					break;
			}
			if (c == '\0')
				break;
		}

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD)) {
		if (isfunc(word))
			continue;
		else if (isalpha(word[0])) //&& binsearch(word, keytab, NKEYS)) {
			root = addtree(root, word);
	}

	treeprint(root);
	return 0;
}

