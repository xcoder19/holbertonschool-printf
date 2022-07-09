#include "main.h"
char *itoa(int val, int base)
{

	static char buf[32] = {0};

	int i = 30;

	for (; val && i; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i + 1];
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
int print_newline(va_list *ap)
{

	(void)ap;
	write(1, "\n", 1);
	return (1);
}
/**
 * print_int - print int
 * @ap:list
 */
int print_int(va_list *ap)
{
	int i;

	i = va_arg(*ap, int);

	write(1, &i, 4);
	return (0);
}
/**
 * print_float - print float
 * @ap: list
 */
int print_float(va_list *ap)
{
	float f;

	f = va_arg(*ap, double);
	printf("%f", f);
	return (0);
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
		str = "(nil)";
	}

	write(1, str, strlen(str));

	return (0);
}
