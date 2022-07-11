#include "main.h"
/**
 * get_op_func - return the correct func to use
 * @s: operation
 * Return: pointer to a function
 */
int (*get_op_func(const char s))(va_list *)
{

	op_t ops[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
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
