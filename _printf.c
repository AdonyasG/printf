#include "main.h"
/**
 * _printf - prints arguments
 * @format: A string of args
 * Return: total printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	convert_match m[] = {
		{"s", print_string}, {"c", print_char}, {"%", print_percent},
		{"d", print_dec}, {"i", print_int},
		{NULL, NULL}
	};
	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = finder(format, m, args);
	va_end(args);
	return (len);
}
