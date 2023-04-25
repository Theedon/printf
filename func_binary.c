#include "main.h"
void _print_binary(unsigned int num, int *count)
{
    if (num > 1)
    {
        _print_binary(num / 2, count);
    }
    _print_char((num % 2) + '0', count);
}

