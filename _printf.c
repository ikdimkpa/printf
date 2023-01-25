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
	char *strings, *rev;
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
			strings = va_arg(ap, char *);
			rev = rev_string(*string):
			for (j = 0; rev[j] != '\0'; j++)
				putchar(rev[j]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			int num;
			
			num = va_arg(ap, int);
			if (num < 0)
			{
				putchar('-');
				fputs(convert(-num, 10), stdout);
			}
			else
			{
				fputs(convert(num, 10), stdout);
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			unsigned int num;
			
			num = va_arg(ap, unsigned int);
			fputs(convert(num, 10), stdout);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			unsigned int hex;

			hex = va_arg(ap, unsigned int);
			fputs(convert(hex, 16), stdout);
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			unsigned int hex;

			hex = va_arg(ap, unsigned int);
			fputs(converts(hex, 16), stdout);
		}
		else if (format[i] == '%' && format[i + 1] == 'o')
		{
			unsigned int oct;

			oct = va_arg(ap, unsigned int);
			fputs(convert(oct, 8), stdout);
		}
		else
			putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
