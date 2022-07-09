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
