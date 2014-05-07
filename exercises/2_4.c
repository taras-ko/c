/*Напишите функцию альтернативную версию функции squeeze(s1,s2),
  которая бы удаляла из строки s1 все символы, встречающиеся в строке s2*/
#include <stdio.h> //getchar(), putchar()
#include <string.h> // strlen()

#define MAXLINE 1000

int my_getline(char s[], int lim);
void copy(char to[], char from[]);

void squeeze(char s[], char t[]); //2.4
void escape(char s[], char t[]); // 3.2
void uescape(char s[], char t[]);//
void expand(char *s1, char *s2); // 3.3

main()
{
	
	char s[MAXLINE], t[MAXLINE] = "";
	
	do	
		printf("s:\n");
	while (my_getline(s, MAXLINE) == 0);

	//do
	//	printf("t:\n");
	//while (my_getline(t, MAXLINE) == 0);
	
//	squeeze(s, t);
//	uescape(s, t);
	expand(s, t);
	printf("res: %s\n", t);

	return 0;
}
void expand (char *s1, char *s2)
{
	int i, j, k, l;

	for (i = 0; s1[i] != '\0' && s1[i] == '-'; i++)
			; // пропускаем все "-" вначале строки
	for (j = strlen(s1) - 1; j > 0 && s1[j] == '-'; j--)
		; // отсекаем все "-" в конце

	l = 0;
	while (i < j) {
		if (s1[i] == '-' && s1[i-1] <= s1[i+1])
			for (k = s1[i-1] + 1; k < s1[i + 1]; k++)
				s2[l++] = k;
		else
	   		s2[l++]	= s1[i];
		i++;
	}
	
	s2[l] = '\0';
}
/* ----------------- 3.2 ----------------------------- */
/* Напишите функцию, которая бы преобразовывала символы 
 * конца строки и табуляции в управляющие последовательности 
 * языка С, такие как \n и \t, в процессе копирования строки t 
 * в строку s. Воспользуйтесь оператором switch. */
void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '\n':
				t[j] = '\\';
				t[++j] = 'n';
				break;
			case '\t':
				t[j] = '\\';
				t[++j] = 't';
				break;
			default:
				t[j] = s[i];
				break;
		}
		++j;
		++i;
	}		
	t[j] = '\0';
}
/* Напишите функцию также и для противоположной операции uescape() - 
 * преобразования символических управляющих последовательностей
 * в фактические управляющие последовательности */
void uescape(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '\\':
				if (s[i+1] = 't') {
					t[j] = '\t';
					i++;
				}
				else if (s[i+1] = 'n') {
					t[j] = '\n';
					i++;
				}
				else
					t[j] = s[i];
				break;
			default:
				t[j] = s[i];
				break;
		}
		++i;
		++j;
	}
	t[j] = '\0';
}
/*----------------2.4---------------------*/
/* напишите альтернативную версию функции squeeze(s1,s2), которая
   бы удаляла из строки s1 все символы, встречающиеся в строке s2. */
void squeeze(char s[], char t[])
{
	int i, j, k;
	char temp[MAXLINE];
	
	for (j = 0; t[j] != '\0'; j++) {
	k = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (t[j] != s[i])
				temp[k++] = s[i];
		}
		temp[k] = '\0';
		copy(s, temp);
	}	
}

int my_getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i) 
		s[i] = c;
	if (c == '\n')	
		s[i++] = c;

	s[i] = '\0';
	
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
			i++;
}
