#include "main.h"

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
/**
 * print_int - prints integer
 * @ap: valist
 * Return: integer
 */
int print_int(va_list *ap)
{
	int i, len;
	int flag = 0;

	i = va_arg(*ap, int);

	if (i < 0)
	{
		flag = 1;
		i = -i;
		write(1, "-", 1);
	}
	len = strlen(convert(i, 10));
	write(1, convert(i, 10), len);

	if (flag)
	{
		return (len + 1);
	}

	return (len);
}
/**
 * convert - converts number into string
 * @num: num
 * @base: base
 * Return: string
 */
char *convert(unsigned int num, int base)
{
	char Representation[] = "0123456789ABCDEF";
	char buffer[50];
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

/**
 * print_binary - convert decimal to binary
 * @n: decimal
 * Return: count
 */
int print_binary(va_list *ap)
{
	int i, flag, len = 0;
	unsigned long k;
	unsigned long int n;

	n = va_arg(*ap, unsigned long int);

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	flag = 0;
	for (i = 63; i >= 0; i--)
	{
		k = n >> i;
		if (k & 1)
		{
			write(1, "1", 1);
			len++;
			flag = 1;
		}
		else if (flag)
		{
			write(1, "0", 1);
			len++;
		}
	}
	return (len);
}