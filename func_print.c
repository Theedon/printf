#include "main.h"
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
