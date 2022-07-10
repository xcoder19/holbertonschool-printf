#include "main.h"
/**
 * _strlen - count length of string
 * @s: pointer to string
 * Return: count
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; ++i)
		;

	return (i);
}
/**
 * print_char - print char
 * @ap: valist
 * Return: 1
 */
int print_char(va_list *ap)
{
	char c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}
/**
 * print_percent - print %
 * @ap: valist pointer
 * Return: 1
 */
int print_percent(va_list *ap)
{

	(void)ap;

	write(1, "%", 1);
	return (1);
}

/**
 * print_str - printstr
 * @ap: list
 * Return: length of string
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

int print_int(va_list *ap)
{

	int i;
	char *p = "";
	i = va_arg(*ap, int);
	IntToString(p, i);
	write(1, p, _strlen(p));
	return (strlen(p));
}

void IntToString(char *s, int x)
{
	char *p = s;
	unsigned t = x;
	char tt;

	if (x < 0)
		t = -t;

	do
	{
		*p++ = '0' + t % 10;
		t /= 10;
	} while (t);

	if (x < 0)
		*p++ = '-';

	while (s < --p)
	{
		tt = *s;
		*s++ = *p;
		*p = t;
	}
}
