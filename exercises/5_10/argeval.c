#include <string.h>
#include "expr.h"

int argeval(char *arg)
{
	if (strlen(arg) == 1 && !isdigit(*arg))
		return *arg; /*вероятно оператор*/
	if (isdigit(*arg) || *arg == '-') {
		while (isdigit(*++arg))
			;
		if (*arg == '.') /* проверка дробной части*/
			while (isdigit(*++arg) && *arg)
				;
		if (*arg == '\0')
			return NUMBER;
	}

	return ERROP;/* ошибочный операнд */		
}
