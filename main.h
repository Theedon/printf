#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

int _printf(const char *format, ...);
void _print_char(char c, int *count);
void _print_string(char *s, int *count);
void _print_binary(unsigned int num, int *count);
void _print_unsigned_decimal(unsigned int num, int *count);
void _print_octal(unsigned int num, int *count);
void _print_hexadecimal(unsigned int num, int uppercase, int *count);
void _print_number(int num, int *count);

#endif /* MAIN_H */
