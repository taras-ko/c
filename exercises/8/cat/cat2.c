#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define STDOUT 1
#define STDIN 0

void _error(int, char *, ...);
char *prog;

main(int argc, char *argv[])
{
	int filecopy(int, int);
	int ifd;

	prog = strdup(argv[0]);

	if (argc == 1)
		filecopy(STDIN, STDOUT);
	else
		while (--argc > 0)
			if ((ifd = open(*++argv, O_RDONLY, 0)) < 0) {
				_error(1, "%s: can't open file %s", prog, *argv);
			} else {
				filecopy(ifd, STDOUT);
				close(ifd);
			}

	if (ferror(stdout))
		_error(2, "%s: error writing stdout", prog);

	exit(0);
}

int filecopy(int ifd, int ofd)
{
	char buf[BUFSIZ];
	int n;

	while ((n = read(ifd, buf, BUFSIZ)) > 0)
		if (write(ofd, buf, n) != n)
			_error(3, "%s: can't write file descriptor %u", prog, ofd);

	return 0;
}

void _error(int n, char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr,"\n");
	va_end(args);
	exit(n);
}
