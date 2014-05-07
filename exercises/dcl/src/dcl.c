#include <stdio.h>
#include <stringlocal.h>
#include <ctypelocal.h>
#include <dcl.h>

#define MAXTOKEN 100

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;		 /* type of last token */
char token[MAXTOKEN];	 /* last token string */
char name[MAXTOKEN];	 /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];		 /* result string */

main()	/* convert declaration to words */
{
	while (gettoken() != EOF) {
		_strcpy(datatype, token); /* 1st token on the line is the datatype */
		dcl();                    /* parse declarator */
		if (tokentype != '\n')    /* parse reset of line */
			printf("syntax error\n");
		else {
			printf("%s: %s %s\n", name, out, datatype);
			out[0]='\0';
		}
	}
	return 0;
}
