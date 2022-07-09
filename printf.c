#include "main.h"
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (0);
	}
	va_list ap;

	char k;
	va_start(ap, format);

	while (*format != '\0')
	{

		if (*format == '%')
		{

			k = *(format + 1);
			if ((get_op_func(k)) != NULL)
			{
				get_op_func(k)(&ap);
			};
		}
		if (*format != '%' && *(format - 1) != '%')
		{
			write(1, format, 1);
		}

		format++;
	}

	va_end(ap);
	return (0);
}
