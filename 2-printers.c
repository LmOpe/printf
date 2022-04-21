#include "main.h"

/**
 * print_string - function that gets string argument,
 * and returns pointer to string argument
 * @v1: va_list type to extract string argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_string(va_list *v1, va_list *v2)
{
	char *s1 = va_arg(*v1, char *), *s2 = va_arg(*v2, char *);
	int len;

	len = 0;
	if (s1 == NULL || s2 == NULL)
	{
		len = _strlen(s1);
		print_to(s1, 0, len);
	}

	return (len);
}

/**
 * print_char - function that extracts and returns char argument
 * @v1: va_list type to extract char argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_char(va_list *v1, va_list __attribute__((__unused__)) *v2)
{
	char s1 = va_arg(*v1, int);
	int len = 0;

	len = _putchar(s1);

	return (len);
}


/**
 * print_int - function that extracts and returns char argument
 * @v1: va_list type to extract char argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_int(va_list *v1, va_list __attribute__((__unused__)) *v2)
{
	int i1, len = 0;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i1 = va_arg(*v1, int);

	len = int_toa(s, i1);
	print_to(s, 0, len);
	free(s);

	return (len);
}

/**
 * print_dec - function that extracts and returns decimal argument
 * @v1: va_list type to extract decimal argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_dec(va_list *v1, va_list *v2)
{
	return (print_int(v1, v2));
}

/**
 * print_double - function that extracts and returns double argument
 * @v1: va_list type to extract double argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_double(va_list *v1, va_list __attribute__((__unused__)) *v2)
{
	double d1 = va_arg(*v1, double);
	int len = 0;
	char *s = malloc(BUFF_SIZE);

	len = float_toa(s, d1, -1);
	print_to(s, 0, len);
	free(s);

	return (len);
}

