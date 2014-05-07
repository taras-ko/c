enum {
	NUMBER,
	VAR_ASSIGN,
	VAR_RETVAL
};

void push(double);
double pop(void);
int getop(char *);
