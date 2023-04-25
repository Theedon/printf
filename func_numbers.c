#include "main.h"
void _print_unsigned_decimal(unsigned int num, int *count)
{
    if (num >= 10)
    {
        _print_unsigned_decimal(num / 10, count);
    }
    _print_char((num % 10) + '0', count);
}

void _print_number(int num, int *count)
{
    if (num < 0)
    {
        _print_char('-', count);
        num = -num;
    }

    _print_unsigned_decimal(num, count);
}

