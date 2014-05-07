/*
 * Упражение 3.5
 *
 */

#include <stdio.h>
#include <string.h> // для strlen
#include <stdlib.h> // для malloc

void itob(int n, char *s, int b);
int capacity(int n, int b);
int power(int b, int s);

main()
{
	int n = 2147483647;
	int b = 16;
	char *s;
	
//	s = malloc(capacity(n, b));
	s = malloc(32);
	
	itob(n, s, b);
	printf("%s\n", s);

	free(s);
	return 0;
}

void itob(int n, char *s, int b)
{
	int B, Bb; //  B = b^i, наибольший делитель числа n.
	int N;  
	int i, prev = 8; 
	int k, j = 0;

while (n) {
	for (i = 0; (Bb = power(b, i)) <= n && Bb > 0; i++) 
		B = Bb;	 //находим наибольший делитель числа n

	i--; // порядковый номер разряда
	
	while (prev - i > 1) { // заполняем нулевые разряды
		s[j++] = '0';
		prev--;	
	}

	prev = i;

	N = n / B; // вес разряда
	n %= B; // остаток для следующей итерации

	if (N <= 9)
		s[j++] = '0' + N;
	else
		s[j++] = 'A' + N % 10;

}
	s[j] = '\0';
}

// возвращает сколько разрядов у числа с b основанием. 
int capacity(int n, int b) 
{
	int i, sum = 0;
	
	for (i = 0; sum < n; i++)
		sum += power(b, i);

	return ++i; // плюс '\0'
}

int power(int b, int s)
{
	int i;
	int res = b;

	for (i = 2; i <= s; i++)
		res *= b;	
	
	if (!s)
		return 1;
	else
		return res;
}
