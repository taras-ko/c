#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

main(int argc, char *argv[])
{
	FILE *fa, *fb;
	char lna[MAXLINE], lnb[MAXLINE];
	char *prog = argv[0];

	if (argc < 3) {
		fprintf(stderr, "%s: not enough parameters\n", prog);
		exit(1);
	}

	if ((fa = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", prog, *argv);
		exit(1);
	}

	if ((fb = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", prog, *argv);
		exit(1);
	}

	while (fgets(lna, MAXLINE - 1, fa) != NULL &&
			fgets(lnb, MAXLINE - 1, fb) != NULL) {
		if (strcmp(lna, lnb)) {
			printf("%s", lna);
			printf("%s", lnb);
			break;
		}
	}

	exit(0);
}
