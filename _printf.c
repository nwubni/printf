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

int print_number(long int n)
{
	unsigned long int t, m;
	int len = 0, zeroes = 0;

	t = (unsigned long int)n;

	if (n < 0)
	{
		len = _putchar('-');
		t = (unsigned long int)(n * (-1));
	}

	while (t && (t % 10) == 0)
	{
		zeroes++;
		t /= 10;
	}

	while (t)
	{
		m = (m * 10) + (t % 10);
		t /= 10;
		len++;
	}

	while (m)
	{
		_putchar((m % 10) + '0');
		m /= 10;
	}

	while (zeroes)
	{
		_putchar('0');
		zeroes--;
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
		count += print_number(va_arg(args, long int));
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
	int count = 0, val;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			val = formatter(*format, args);

			if (val == -1)
				return (-1);

			count += val;
		}
		else
			count += _putchar(*format);

		format++;
	}

	va_end(args);

	return (count == 0 ? -1 : count);
}
