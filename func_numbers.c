#include "main.h"

/**
 * _print_unsigned_decimal - function that prints an unsigned decimal
 * @num: int to be printed in unsigned decimal
 * @count: The pointer to the int
 * Return: The number of chars printed
 */
void _print_unsigned_decimal(unsigned int num, int *count)
{
	if (num >= 10)
	{
		_print_unsigned_decimal(num / 10, count);
	}
	_print_char((num % 10) + '0', count);
}

/**
 * _print_number - function that prints a number
 * @num: The nummber to be printed
 * @count: The pointer to the int
 * Return: The number of chars printed
 */
void _print_number(int num, int *count)
{
	if (num < 0)
	{
		_print_char('-', count);
		num = -num;
	}
	_print_unsigned_decimal(num, count);
}

