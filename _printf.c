#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void _print_char(char c, int *count);
void _print_string(char *s, int *count);
void _print_binary(unsigned int num, int *count);
void _print_unsigned_decimal(unsigned int num, int *count);
void _print_octal(unsigned int num, int *count);
void _print_hexadecimal(unsigned int num, int uppercase, int *count);

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
                printf("%d", num);
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
    return count;
}

void _print_char(char c, int *count)
{
    putchar(c);
    (*count)++;
}

void _print_string(char *s, int *count)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '%')
        {
            putchar(s[i]);
            (*count)++;
        }
        else if (s[i + 1] == '%')
        {
            putchar('%');
            (*count)++;
            i++;
        }
    }
}

void _print_binary(unsigned int num, int *count)
{
    if (num > 1)
    {
        _print_binary(num / 2, count);
    }
    _print_char((num % 2) + '0', count);
}

void _print_unsigned_decimal(unsigned int num, int *count)
{
    if (num >= 10)
    {
        _print_unsigned_decimal(num / 10, count);
    }
    _print_char((num % 10) + '0', count);
}

void _print_octal(unsigned int num, int *count)
{
    if (num >= 8)
    {
        _print_octal(num / 8, count);
    }
    _print_char((num % 8) + '0', count);
}

void _print_hexadecimal(unsigned int num, int uppercase, int *count)
{
    char hex_digits[] = "0123456789abcdef";
    char hex_digit;

    if (num >= 16)
    {
        _print_hexadecimal(num / 16, uppercase, count);
    }
    hex_digit = hex_digits[num % 16];
    if (uppercase)
    {
        hex_digit = toupper(hex_digit);
    }
    _print_char(hex_digit, count);
}
