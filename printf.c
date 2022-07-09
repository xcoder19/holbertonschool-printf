#include "main.h"
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0;
	char k;
	const char *p = format;
	if (format == NULL)
	{
		return (-1);
	}

	va_start(ap, format);

	while (*format != '\0')
	{

		if (*format == '%')
		{

			k = *(format + 1);
			if ((get_op_func(k)) != NULL)
			{

				len = len + (get_op_func(k)(&ap));
			};
		}
		if (*format != '%' && *(format - 1) != '%')
		{
			write(1, format, 1);
		}

		format++;
	}
	if (*format == '\n')
	{
		write(1, "\n", 1);
	}

	va_end(ap);
	return (_strlen(p) + len - 2);
}
