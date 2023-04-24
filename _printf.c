#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/** A project by Nakuru and */

/**
* _putchar - Function to print a character
* @c: Character parameter
* Return: Integer
*/

int _putchar(char c)
{
	return (putchar(c));
}

/**
* _printf - A printf function
* @format: String format parameter
* Return: Integer
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				count += _putchar(va_arg(args, int));
				break;
				case 's':
				count += printf("%s", va_arg(args, char *));
				break;
				case '%':
				count += _putchar('%');
				break;
				default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}
