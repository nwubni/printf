#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/** A project by Nakuru and Anifred*/

/**
* _putchar - Function to print a character
* @c: Character parameter
* Return: Integer
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_string - Prints a string
* @s: String parameter
* Return: Integer
*/

int print_string(char *s)
{
	int i = 0;

	while (s && *s)
	{
		i += _putchar(*s);
		s++;
	}

	return (i);
}

/**
* _printf - A printf function
* @format: String format parameter
* Return: Integer
*/

int _printf(const char *format, ...)
{
	int count = 0;
	char *str;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

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
				str = va_arg(args, char *);
				count += print_string((str == NULL ? "(null)" : str));
				break;
				case '%':
				count += _putchar('%');
				break;
				default:
				count += _putchar('%');
				break;
			}
		}
		else
			count += _putchar(*format);

		format++;
	}
	va_end(args);
	return (count == 0 ? -1 : count);
}
