#include <stdio.h>
#define HEX_BASE 16 //база 16-ричного числа
#define MAX_HEX_LENGTH 8

int hexpower(int n);
int htoi(char s[], int len);
int getline2(char s[], int lim);

main()
{
	char hexline[MAX_HEX_LENGTH];
	int hexlen;

	while ((hexlen = getline2(hexline, MAX_HEX_LENGTH)) > 0)
		printf("%d\n", htoi(hexline, hexlen));

	return 0;
}

/* вычисляем степени 16 */
int hexpower(int n)
{
	int i, \
		p = 1;

	for (i = 1; i<=n; ++i)
		p *= HEX_BASE;

	return p;
}

int htoi(char s[], int len)
{
	int i, j, n;

	n = j = 0;
	for (i = len - 1; i >= 0 &&  s[i] != 'x' && s[i] != 'X' && \
	    (s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || \
		 s[i] >= 'A' && s[i] <= 'F'); --i) {
		
		if (s[i] >= '0' && s[i] <= '9') { 		
			n += hexpower(j) * (s[i] - '0');
			++j;
		}
		else if (s[i] >='a' && s[i] <= 'f') {
			n += hexpower(j) * (s[i] - 'a' + 10);
			++j;
		}
		else { /* в случае A...F */
			n += hexpower(j) * (s[i] - 'A' + 10);
			++j;
		}
	}

    return n;
}

/* считаем строку, содержащую шестнадцатиричное число */
int getline2(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i) 
		s[i] = c;
	
	s[i + 1] = '\0';
	
	return i;
}
