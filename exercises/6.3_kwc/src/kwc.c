/* kwc - Keyword Counter */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <bintree.h>
#include <parser.h>

#define MAXWORD 100

FILE *stream = NULL;

void parse_args(int argc, char *argv[])
{
	char c;
	int n;

	while (--argc > 0 && (*++argv)[0] == '-') {
		c = *++argv[0];
		switch (c) {
			case 'h':
				printf("Usage: kwc [-h][-number][-f input file] \"input text...\"\n");
				break;
			case 'f': {
				char *input_file = *++argv;
				stream = fopen(input_file, "r");
				if (!stream)
					perror("Couldn't open file parsing from stdin...\n");
				argc--;
				break;
			}
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

	if (!stream)
		stream = stdin;
}
/* Count C language keywords in a file */
int main(int argc, char *argv[])
{
	parse_args(argc, argv);

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

	if (stream != stdin)
		fclose(stream);
	return 0;
}

