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
	int i, j, num;
	char *strings, *rev;
	va_list ap;
	unsigned int hex;

	i = j = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		    switch (format[i + 1]) {
			    case 'c':
			    {
				    putchar(va_arg(ap, int));
				    i++;
			    }
			    case 's':
			    {
				    strings = va_arg(ap, char *);
				    for (j = 0; strings[j] != '\0'; j++)
					    putchar(strings[j]);
				    i++;
			    }
			    case '%':
			    {
				    putchar('%');
				    i++;
			    }
			    case 'r':
			    {
				    strings = va_arg(ap, char *);
				    rev = rev_string(strings);
				    for (j = 0; rev[j] != '\0'; j++)
					    putchar(rev[j]);
				    i++;
			    }
			    case 'd':
			    {
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
			    }
			    case 'i':
			    {
				    hex = va_arg(ap, unsigned int);
				    fputs(convert(hex, 10), stdout);
			    }
			    case 'x':
			    {
				    hex = va_arg(ap, unsigned int);
				    fputs(convert(hex, 16), stdout);
			    }
			    case 'X':
			    {
				    hex = va_arg(ap, unsigned int);
				    fputs(converts(hex, 16), stdout);
			    }
			    case 'o':
			    {
				    hex = va_arg(ap, unsigned int);
				    fputs(convert(hex, 8), stdout);
			    }
			    default
				    putchar(format[i]);
			    i++;
	}
	va_end(ap);
	return (0);
}
