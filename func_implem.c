#include "main.h"
int _strlen(const char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; ++i)
		;

	return (i);
}
char *itoa(int val, int base)
{

	static char buf[32] = {0};

	int i = 30;

	for (; val && i; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return (&buf[i + 1]);
}
int print_char(va_list *ap)
{
	char c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}
int print_percent(va_list *ap)
{

	(void)ap;

	write(1, "%", 1);
	return (1);
}

/**
 * print_str - print str
 * @ap: list
 */
int print_str(va_list *ap)
{
	char *str;

	str = va_arg(*ap, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	write(1, str, _strlen(str));

	return (_strlen(str));
}
