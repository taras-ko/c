#include <stdio.h>
#include <stdlib.h> // для atof()
#include <math.h> // для sin(), exp(), pow()
#include "calc.h"

#define MAXOP 100 // максимальный размер операнда или знака

/* калькулятор с обратной польской записью */
main()
{
	int type;
	double op2, x, y, z;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push( pop() + pop() );
				break;
			case '*':
				push( pop() * pop() );
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					printf("error: zero divisor\n");
				break;
			case 'p':
				y = pop();
				x = pop();
				if (x = 0 && y <= 0)
					printf("error: x = 0 && y <= 0, pow() error\n");
				else if (x < 0)
						push(pow(x, (int) y));
				else
					push( pow(x, y) );
				break;
			case 'e':
				push( exp(pop()) );
				break;
			case 'c':
				push( cos(pop()) );
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
