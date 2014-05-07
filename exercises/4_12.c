/* 4_12_13_14 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//malloc
char * ritoa(char *a, int n, int i); // recursive itoa
void reverse(char *s, int left, int right);

#define swap(t,x,y) {\
						typeof(x) tmp  = x, x = y, y = tmp;\
					}

main()
{
	char *a = NULL, *s = "Hello world!", s2[] = "Hello world!";
	int n = -123456;
	

//	a =	ritoa(a, n, 0);
//	reverse(s, 0, strlen(s) - 1);

//	printf("%s\n, %s\n", a, s);

	char x = 'x', y = 'y';

	swap(char, x, y);

	({
		typeof(x) c;
	});

	free(a);
//	free(s);

	return 0;
}


char * ritoa(char *a, int n, int i)
{
	char sign = 1;
	static int end; // внутренняя статическая переменная, которая сохраняет номер посл символа в строке

	if (n < 0)	{
		sign = -1;	
		n *= -1;
		i++;
	}

	if (n > 0)
		a = ritoa(a, n / 10, i + 1);
	else {
		a = malloc(i + 1);		
	   	a[i] = '\0';
		end = i;
		return a;
	}

	a[end - i] = '0' + n % 10;
	
	if (sign == -1)
		a[0] = '-';
	
	return a;
}

void reverse(char *s, int left, int right)
{
	char c;

	if (left < right)
		reverse(s, left + 1, right - 1);
	else return;

	c = *(s + left);
   	*(s + left) = *(s + right);
   	*(s + right) = c;

}


