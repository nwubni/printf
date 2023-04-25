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
* print_number - Prints a number
* @n: Number string
* Return: Integer
*/

int print_number(int n)
{
	int m = 0, len = 0;

	if (n < 0)
	{
		len = _putchar('-');
		n *= -1;
	}

	while (n)
	{
		m = (m * 10) + (n % 10);
		n /= 10;
		len++;
	}

	while (m)
	{
		_putchar((m % 10) + '0');
		m /= 10;
	}

	return (len);
}

/**
* formatter - Decides and prints the input format
* @c: Character Parameter
* @args: Arguments for variadic _printf
* Return: Integer
*/

int formatter(char c, va_list args)
{
	int count = 0;
	char *str;

	switch (c)
	{
		case 'c':
		count += _putchar(va_arg(args, int));
		break;
		case 's':
		str = va_arg(args, char *);
		count += print_string((str == NULL ? "(null)" : str));
		break;
		case 'i':
		case 'd':
		count += print_number(va_arg(args, int));
		break;
		case '%':
		count += _putchar('%');
		break;
		default:
		if (c == '\0')
			return (-1);

		count += _putchar('%');
		count += _putchar(c);
		break;
	}

	return (count);
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
			count += formatter(*format, args);
		}
		else
			count += _putchar(*format);

		format++;
	}

	va_end(args);

	return (count == 0 ? -1 : count);
}
