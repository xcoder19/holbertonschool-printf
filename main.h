#ifndef _main_h
#define _main_h
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(va_list *ap);
} op_t;
int _printf(const char *format, ...);
char *convert(unsigned int num, int base);
int print_char(va_list *ap);
int print_int(va_list *ap);
int print_float(va_list *ap);
int print_str(va_list *ap);
int print_percent(va_list *ap);
void puts2(char *str);
int _strlen(const char *s);
int (*get_op_func(const char s))(va_list *ap);
#endif
