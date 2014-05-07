#include <stdio.h>

#define SIZE 10

main()
{
	int n, array[SIZE], getint(int *), getfloat(double *);
	double farray[SIZE];

	for (n = 0; n < SIZE && getfloat(&farray[n]) != EOF; n++)
		;
	for (; n < SIZE; n++)
		farray[n] = 0.0;

	return 0;
}

#include <ctype.h>
int getch(void);
void ungetch(char c);

int getfloat(double *pf)
{
	int c, c2;	
	double sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* не цифра */
		return 0;
	}
	sign = (c == '-') ? -1.0 : 1.0;
	if (c == '+' || c == '-') {
		c2 = c;
		if (!isdigit(c = getch())) {
			ungetch(c);
		   	ungetch(c2);
			return 0;
		}
	}
	for (*pf = 0.0; isdigit(c); c = getch()) /* накопление целой части */
		*pf = 10.0 * *pf + (double) (c - '0');
	if (c == '.') {
		double factor = 1.0;
		while ( isdigit(c = getch()) ) { /* накопление дробной части */	
			factor /= 10.0;
			*pf += factor * (double) (c - '0'); 
		}
	}
	*pf *= sign;
	
	if (c != EOF)
		ungetch(c);
	return c;
}

int getint(int *pn)
{
	int c, c2, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* не цифра */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c2 = c;
		if (!isdigit(c = getch())) {
			ungetch(c);
		   	ungetch(c2);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(char c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
