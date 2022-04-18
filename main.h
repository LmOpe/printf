#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - function that prints output according to format
 * @format: string that determines the conversion,
 * specifiers.
 * Return: the number of characters printed
 */

int _printf(const char *format, ...);


char print_cha(va_list *ap);
char print_int(va_list *ap);
char print_str(va_list *ap);
char *rev_string(va_list *ap);
char *rot13(va_list *ap);

/**
 * count_specifiers - function that counts and returns the numbers,
 of specifiers found.
 * @s: string to count specifiers
 * Return: the number of specifiers found
 */

int count_specifiers(char *s);

/**
 * get_specifiers - function that extract specifiers and return,
 the specifier types.
 * @s: string to extract specifiers
 * @n: number of specifiers
 */

char *get_specifiers(char *s, int n);

/**
 * get_string - function that gets string argument,
 and returns pointer to string argument
 * @v: va_list type to extract string argument
 * Return: pointer to string argument
 */

char *get_string(va_list *v);

/**
 * get_char - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: extracted char argument
 */

char get_char(va_list *v);

/**
 * get_double - function that extracts and returns double argument
 * @v: va_list type to extract double argument
 * Ret
double get_double(va_list *v);

#endif
