#include "main.h"
/**
 * finder - finds the specifier
 * @format: pointer
 * @m: struct
 * @args: number of argument
 * Return: len
 */
int finder(const char *format, convert_match m[], va_list args)
{
	int i, j, r_val, len = 0;

	for (i = 0; format[i] != '\0'; i++)
	if (format[i] == '%')
	{
		for (j = 0; m[j].id != NULL; j++)
		{
			if (format[i + 1] == m[j].id[0])
			{
				r_val = m[j].f(args);
				if (r_val == -1)
					return (-1);
				len += r_val;
				break;
			}
		}
		if (m[j].f == NULL && format[i + 1] != ' ')
		{
			if (format[i + 1] != '\0')
			{
				_putchar(format[i]);
				_putchar(format[i + 1]);
				len +=  2;
			}
			else
				return (-1);
		}
		i++;
	}
	else
	{
		_putchar(format[i]);
		len++;
	}
	return (len);
}

