#include <stdio.h>
#include <stdarg.h>

/* minprintf: limited edition printf
 * with variable range of arguments */
void minprintf(char *fmt, ...)
{
	va_list ap; /* pointer to the unnamed arguments */
	char *p, *sval;
	int ival;
	int *ivalp;
	double dval;

	va_start(ap, fmt); /* set ap to the first unnamed argument */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
			case 'd':
				ip = va_arg(ap, int *);
				printf("%d", ival);
				break;
			case 'f':
				dp = va_arg(ap, double *);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*sval);
				break;
		}
	}
	va_end(ap); /* endiness operation */
}

main()
{
	minprintf("This is decimal: %d\nAnd that is a float: %f\nThe string: %s\n",
			10, 10.00001, "Hello World!");
}
