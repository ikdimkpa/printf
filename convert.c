#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
/**
 * convert - Build out the printf function
 * num: string passed with possible format specifiers
 * base: base of conversion
 * Return: number of characters printed
 */
char *convert(unsigned int num, int base)
{
	static char Representation[] = "0123456789abcdef";
	static char buffer[50];
	char *ptr;
	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*--ptr = Representation[num % base];
		num /= base;
	}
	while (num != 0);
	return (ptr);
}
/**
 * converts - Build out the printf function
 * num: string passed with possible format specifiers
 * base: base of conversion
 * Return: number of characters printed
 */
char *converts(unsigned int num, int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;
	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*--ptr = Representation[num % base];
		num /= base;
	}
	while (num != 0);
	return (ptr);
}
