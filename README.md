## Printf

## this is the implementation of the printf function

## Usage && Examples

Include main.h Call \_printf, passing a formatted string with any format specifiers and optional arguments Upon success, it writes desired output to stdout Upon error, it returns -1 If NULL is passed in as a string argument, it prints (null) Format Specifier.

To use the \_printf function you simply need to compile all files .c including the header holberton.h with a main function.

```c
'#include "main.h"

int main(void) { _printf("let's print hello holberton!");

return (0); }
```

Compilation:

```sh
$ gcc *.c -o
```

Output:

```sh
let's print hello holberton!
```

You can do much more, by combining specifiers like string or integer.

## Files

Below a list of the used files during project:

- [_printf.c] - produces output according to a format.
- [func_implem.c] - containing functions for specifiers.
- [get_op_func.c] - containing function that returns pointer to the selected function.
- [main.h] - header file with function prototypes and struct for specifiers.

## DEVS

**hedi ben hamida**

- (https://github.com/xcoder19)

**dhafer hamaza**

- (https://github.com/dhaferhs)
