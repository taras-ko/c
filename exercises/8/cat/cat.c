#include <stdio.h>
#include <_stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
	_FILE *fp;
	void filecopy(_FILE *, _FILE *);
	char *prog = argv[0];

	if (argc == 1) /* no args stdin -> stdout */
		filecopy(_stdin, _stdout);
	else
		while (--argc > 0)
			if ((fp = _fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			} else {
				filecopy(fp, _stdout);
				//fclose(fp);
			}
	if (_ferror(_stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

void filecopy(_FILE *ifp, _FILE *ofp)
{
	int c;

	while ((c = _getc(ifp)) != EOF)
		_putc(c, ofp);
}
