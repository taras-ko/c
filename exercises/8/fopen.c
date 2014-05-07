#include <stdio.h>
#include <_stdio.h>

main(int argc, char *argv[])
{
	_FILE *fp;
	int c;

	if (argc == 1)
		;
	else
		if ((fp = _fopen(*++argv, "r")) == NULL)
			return 1;
		else {
			while ((c = _getc(fp)) != EOF)
				_putchar(c);
			_fclose(fp);
		}
	return 0;
}
