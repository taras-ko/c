/* 
 * Упражнение 3.4
 *
 */
#include <stdio.h>
#include <string.h> 
#define MAXLINE 1000

void itoa(int n, char *s, int minlen);
void reverse(char *s);
int my_getline (char *s, int lim);
int power(int b, int s);

main()
{
	int n = power(2, 31);
	char s[MAXLINE];	

	itoa(n, s, 15);	
	printf("string res: %s\n", s);
	
	return 0;
}

void itoa(int n, char *s, int minlen)
{
	int i, sign;

	sign = (n > 0) ? 1 : -1;

	i = 0;
   	do 	/* генерируем цифры в обратном порядке */
		s[i++] = n % 10 * sign + '0';	/* извлекаем цифру */
	while ((n /= 10) != 0);		/* удаляем ее */		

	if (sign < 0)
		s[i] = '-';
	
	while (minlen - 1 > i++)
		s[i] = '_'; 
	
	s[i] = '\0';

	reverse(s);	
}

int power(int b, int s)
{
	int i;
    int res;

	res = b;
	for (i = 2; i <= s; i++)
		res *= b;

	return res;
}

void reverse(char *s)
{
	int i, j, c;

	for (i = 0, j = strlen(s) - 1;  i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

int my_getline(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	
	s[i] = '\0';

	return i;
}
