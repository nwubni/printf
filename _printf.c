#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/** A project by Nakuru and Anifred Thomas Oruama*/

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
* @num: Number string
* Return: Integer
*/

int print_number(int num)
{
	int dig_len = 0, first = num, count = 0, x = 1, i, tmp;

	tmp = num;

	if (num < 0)
	{
		dig_len += _putchar('-');
		num = (num * -1) - 1;
	}

	while (first != 0)
	{
		first /= 10;
		count++;
	}

	while (x <= count)
	{
		first = num;
		i = x;

		while (i < count)
		{
			first /= 10;
			i++;
		}

		if (tmp < 0 && x == count)
			dig_len += _putchar(((first % 10) + 48) + 1);
		else
			dig_len += _putchar((first % 10) + 48);
		x++;
	}

	if (count == 0)
		dig_len += _putchar('0');

	return (dig_len);
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
