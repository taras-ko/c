int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else
		return c;
}

int _islower(int c)
{
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z'))
		return 1;
	else
		return 0;
}

int _isalnum(int c)
{
	return isalpha(c) || (c >= '0' && c <='9');
}

int _isspace(int c)
{
	switch (c) {
		case ' ':
		case '\t':
		case '\n':
			return 1;
			break;
		default:
			break;
	}

	return 0;
}

int _isdigit(int c)
{
	return c >= '0' && c <= '9';
}
