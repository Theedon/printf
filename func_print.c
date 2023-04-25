#include "main.h"

/**
 * _print_char - A fuction that prints a character
 * @c: The character to be printed
 * @count: pointer to the int
 */
void _print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * _print_string - A function that prints a string
 * @s: The string to be printed
 * @count: pointer to the int
 */
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
