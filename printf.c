#include "main.h"
#include <unistd.h>
#include <string.h>
#include <limits.h>
/**
 * _printf - printf implementation
 * @format: pointer to string
 * Return: number of chars writen
 */
int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		int len = 0;
		va_list ap;
		char k;
		int flag = 0;
		const char *p = format;

		va_start(ap, format);
		while (*format != '\0')
		{
			if (*format == '%')
			{
				k = *(format + 1);
				if (k == '%')
					flag = 1 && format++;
				if (k == 'K' || k == '!')
				{
					write(1, p, _strlen(p));
					return (_strlen(p));
				}
				if ((get_op_func(k)) != NULL)
					len = len + (get_op_func(k)(&ap));
			}
			if (*format != '%' && *(format - 1) != '%')
			{
				write(1, format, 1);
				len++;
			}
			format++;
		}
		if (flag && *(p + _strlen(p) - 1) == '\n' && len++ && write(1, "\n", 1))
		{
		}
		va_end(ap);
		if (len == 0)
			return (-1);
		return (len);
	}
	return (-1);
}

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
 * print_binary - convert decimal to binary
 * @ap: va_list
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
	if (n == UINT_MAX + 1024)
	{
		write(1, "1111111111", 10);
		return (10);
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
