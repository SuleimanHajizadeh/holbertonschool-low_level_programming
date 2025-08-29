#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on the format string
 * @format: list of types of arguments passed
 * c: char, i: int, f: float, s: char * (NULL prints (nil))
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' ||
		    format[i] == 'f' || format[i] == 's')
		{
			if (format[i] == 'c')
				printf("%s%c", separator, va_arg(args, int));
			if (format[i] == 'i')
				printf("%s%d", separator, va_arg(args, int));
			if (format[i] == 'f')
				printf("%s%f", separator, va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", separator, str);
			}
			separator = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
