#include <stdio.h>
#include <string.h>

#define SUBSTSYM ' '
#define SUBSTNUM 4

main(int argc, char **argv)
{
	int snum = 0; /* spaces number */
	char ssym;

	if (argc != 2) {
		ssym = SUBSTSYM;
		snum = SUBSTNUM;	
	}
	else {
		char *s = *(argv + 1);
		if (*s == '-' && *(s + 1) == 'h') {
			printf("Usage: entab '[spaces]' stdin\n");
			return 0;
		}
		for (; *s; s++)
			if (*s == SUBSTSYM)
				snum++;
	}

	int c, sc; /* space_bar counter */

	c = sc = 0;	
	while (c != EOF) {
		while ((c = getchar()) == '_' && c != EOF) {
			sc++;
		}
		ungetc(c, stdin);

			for (; sc / snum; sc -= snum)
				putchar('\t');
			for (; sc; sc--)
				putchar('_');

		while ((c = getchar()) != '_' && c != EOF)
			putchar(c);	
		ungetc(c, stdin);
	}

	return 0;
}
