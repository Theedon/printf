#include "main.h"
#include <stdarg.h>
#include <ctype.h>

void _print_char(char c, int *count);
void _print_string(char *s, int *count);
void _print_binary(unsigned int num, int *count);
void _print_unsigned_decimal(unsigned int num, int *count);
void _print_octal(unsigned int num, int *count);
void _print_hexadecimal(unsigned int num, int uppercase, int *count);
void _print_number(int num, int *count);

/**
 * _printf - A fuction that produces an output according to a format
 * @format: Is the character string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_print_char('%', &count);
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				_print_char(c, &count);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				_print_string(s, &count);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				_print_number(num, &count);
				count++;
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				_print_binary(num, &count);
			}
		}
		else
		{
			_print_char(*format, &count);
		}
		format++;
	}

	va_end(args);
	return (count);
}
