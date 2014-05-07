#include <stdio.h>
#include <stringlocal.h>
#include <dcl.h>
/* dcl:		optional *'s direct-dcl
 * direct-dcl:	name
 *		(dcl)
 *		direct-dcl()
 *		direct-dcl[optional size]
 */

extern char out[1000];

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;
	void dirdcl(void);

	for (ns = 0; gettoken() == '*'; )
		ns++;
	dirdcl();
	while (ns-- > 0)
		_strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;
	extern int tokentype;
	extern char name[], token[];

	if (tokentype == '(') { /* ( dcl ) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME) /* variable name */
		_strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			_strcat(out, " function returning");
		else {
			_strcat(out, " array");
			_strcat(out, token);
			_strcat(out, " of");
		}
}
