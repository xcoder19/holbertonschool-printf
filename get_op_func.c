#include "main.h"

int (*get_op_func(const char s))(va_list *ap)
{

	op_t ops[] = {
		{"c", print_char},
		{"\n", print_newline},
		{"%", print_percent},
		{"s", print_str},

		{NULL, NULL}};

	int i;

	i = 0;

	while (ops[i].op)
	{

		if (strchr(ops[i].op, s) == ops[i].op)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
