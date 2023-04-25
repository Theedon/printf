#include "main.h"

/**
 * _print_binary - A function that prints numbers in binary
 * @num: number to printed in binary
 * @count: pointer to the int
 * Return: The number of characters printed
 */
void _print_binary(unsigned int num, int *count)
{
	if (num > 1)
	{
		_print_binary(num / 2, count);
	}
	_print_char((num % 2) + '0', count);
}

