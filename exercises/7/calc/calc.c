#include <stdio.h>
#include <string.h>

void push(double);
double pop(void);

main()
{
	int res;
	float f;
	char op;
	void *px;

	char *fmt = readflt;
	px = (void *)&f;

	while ((res = scanf(fmt, px)) != EOF) {
		switch (res) {
			case 1:
				if (strcmp(fmt, readflt) == 0)
					push(*((float *)px));
				else
					switch (*((char *)px)) {
						case '+':
							push(pop() + pop());
						default:
							printf("error: unrecongnized operator %c\n", op);
							break;
					}
				break;
			case 0:
				if (strcmp(fmt, readop) == 0) {
					fmt = readflt;
					px = (void *)&f;
				} else {
					fmt = readop;
					px = (void *)&op;
				}
			default:
				break;
		}
	}

	printf("%f\n", pop());
}
