#include "main.h"

/**
 * _print_octal - A function that prints a num in octal
 * @num: int to be printed in octal
 * @count: pointer to the int
 * Return: The numbers of chars printed
 */
void _print_octal(unsigned int num, int *count)
{
	if (num >= 8)
	{
		_print_octal(num / 8, count);
	}
	_print_char((num % 8) + '0', count);
}

/**
 * _print_hexadecimal - A function that prints a num in hexadecimal
 * @num: num to be printed in hexadecimal
 * @uppercase: int to print the hexadecimal in uppercase
 * @count: pointer to the int
 * Return: The number of characters to be printed
 */
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
