#include "main.h"
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		int len = 0;
		va_list ap;
		char k;
		int flag = 0;
		const char *p = format;
		int m = _strlen(format);

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
					write(1, p, m);
					return m;
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
		if (flag && *(p + m - 1) == '\n')
		{
			len++;
			write(1, "\n", 1);
		}
		va_end(ap);
		if (len == 0)
			return (-1);

		return (len);
	}
	return (-1);
}
