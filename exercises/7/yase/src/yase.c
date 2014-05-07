#include <stdio.h>
#include <ctype.h>
#include <debug.h>

#define MAXWORD 100

#define FMT_MAXLINE 80

void print_usage(void)
{
	printf("Usage:\n"
"\t-i invert case of each character.\n"
"\t-f format text\n");
}

struct {
	unsigned int do_invert : 1;
	unsigned int do_format : 1;
} flags = {
	0,
	0,
};

main(int argc, char *argv[])
{
	int c;
	int cnt; /* will count number of characters against FMT_MAXLINE */
	char s[MAXWORD];
	char *sp = NULL;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0]) {
			switch (c) {
				case 'h':
					print_usage();
					break;
				case 'i':
					flags.do_invert = 1;
					break;
				case 'f':
					flags.do_format = 1;
				default:
					break;
			}
		}

	for (cnt = 0; (c = getchar()) != EOF; cnt++) {
		if (flags.do_invert)
			c = _islower(c) ? toupper(c) : tolower(c);
		if (flags.do_format) {
			if (c != '\n' && isspace(c)) {
				sprintf(s, "_0x%X_", c);
				sp = s;
			}
			if (cnt >= FMT_MAXLINE) {
				cnt = 0;
				putchar('\n');
			}
		}
		if (sp == NULL)
			putchar(c);
		else {
			printf("%s", sp);
			sp = NULL;
		}
	}

	return 0;
}
