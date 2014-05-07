#include <stdio.h>
#include <stdarg.h>

#include <mystdlib.h>
#include <ctypelocal.h>
#include <mystdlib.h>

#define MAXWORD 100

void getd(char *t, char *s)
{
	while (_isdigit(*s))
		*t++ = *s++;
	*t = '\0';
}

int minscanf(char *fmt, ...)
{
	int c, cnt = 0;
	va_list ap;
	char *p;
	int *intp;
	char inputstr[MAXWORD];
	char d[MAXWORD];
	char *dp, *argsp;
	char *sp = inputstr;

	while ((c = getchar()) != EOF && c != '\n')
		*sp++ = c;
	*sp = '\0';
	sp = inputstr;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			continue;
		}
		switch (*++p) {
			case 'd':
				intp = va_arg(ap, int *);
				dp = d;
				while (_isspace(*sp))
					sp++;
				while (_isdigit(*sp))
					*dp++ = *sp++;
				*dp = '\0';
				*intp = _atoi(d);
				cnt++;
				break;
			case 's':
				argsp = va_arg(ap, char *);
				while (_isspace(*sp))
					sp++;
				while (!_isspace(*sp))
					*argsp++ = *sp++;
				*argsp = '\0';
				cnt++;
				break;
			default:
				break;
		}
	}
	va_end(ap);

	return cnt;
}

main()
{
	int day, month, year;
	char monthname[20];
	scanf("%d %s %d", &day, monthname, &year);
	printf("Now is %d of %s %d\n", day, monthname, year);
}
