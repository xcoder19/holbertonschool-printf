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
	int flag = 0;
	char *p = "";
	i = va_arg(*ap, int);

	if (i < 0)
	{
		flag = 1;
		i = -i;
		putchar('-');
	}
	p = convert(i, 10);
	puts2(p);
	if (flag)
	{
		return (_strlen(p) + 1);
	}
	return (_strlen(p));
}
int print_integer(va_list *ap)
{
	int i;
	int flag = 0;
	char *p = "";
	i = va_arg(*ap, int);

	if (i < 0)
	{
		flag = 1;
		i = -i;
		write(1, "-", 1);
	}
	p = convert(i, 10);
	puts2(p);
	if (flag)
	{
		return (_strlen(p) + 1);
	}
	return (_strlen(p));
}

char *convert(unsigned int num, int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
void puts2(char *str)
{

	write(1, str, _strlen(str));
}
