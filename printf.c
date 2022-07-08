#include "main.h"
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...)
{
	va_list ap;
	int newLine = 0;
	char k;
	va_start(ap, format);

	while (*format != '\0')
	{

		if (*format == '%')
		{
			newLine = 1;

			k = *(format + 1);
			get_op_func(k)(&ap);
		}

		format++;
	}
	if (*(format - 1) == '\n' && newLine)
	{
		write(1, "\n", 1);
	}

	va_end(ap);
	return (0);
}
