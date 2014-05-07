/*
*
* Упражение 4.2
*
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define elementary_charge "1.602176565E-19"
//#define Постоянная_Больцмана "1.380650424E-23"
//#define число_Авогадро "6.02214179E23"

int my_getline(char *line, int lim);
int atoi(char *s);
double atof(char *s);

main()
{
	char line[MAXLINE] = elementary_charge;

/*	while (my_getline(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("%s\n", line);
			return 1;
		}
*/
	printf("%.12e\n", atof(line));

	return 0;
}

int my_getline(char *s, int lim)
{
	int i, c;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
int atoi(char *s)
{
	int n, i;

	for (i = 0, n = 0; isdigit(s[i]); i++)
		n = n * 10 + (s[i] - '0');

	return n;
}

double atof(char *s)
{
	double val, power, expower, expmult;
	int i, j, sign, e;//exponential multiplier, exponent (порядок)
	char exp_s[10] = ""; //	строка, в которую будет записан порядок мантиссы

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] = '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'E' || s[i] == 'e') {
		i++;
		if (s[i] == '-') {
			expmult = 0.10;
			i++;
		}
		else expmult = 10.0;

		for (j = 0; isdigit(s[i]); i++, j++)
			exp_s[j] = s[i];
		exp_s[j] = '\0';	
		
		e = atoi(exp_s);
		for (j = 0, expower = 1.0; j < e; j++) 
			expower *= expmult;
		
	}
	return sign * val / power * expower;
}
