#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stddef.h>
#include "main.h"
/**
 * _printf - the new function for printing
 * @format: the first details
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	int i, j;
	char *strings;
	va_list ap;

	i = j = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			putchar(va_arg(ap, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			strings = va_arg(ap, char *);
			for (j = 0; strings[j] != '\0'; j++)
				putchar(strings[j]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'r')
		{
			putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd')
		{
			int num, temp;
			
			num = va_arg(ap, int);
			temp = num;
			if (num < 0)
			{
				num = -num;
			}
			if (temp < 0)
			{
				putchar ('-');
			}
			fputs(convert(num, 10), stdout);
			i++;
		}
		else if (format[i] == '%' &&  || format[i + 1] == 'i')
			 int num;
			
			num = va_arg(ap, int);
			if (num < 0)
			{
				num = -num;
			}
			fputs(convert(num, 10), stdout);
			i++;
		else
			putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
