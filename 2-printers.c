#include "main.h"

/**
 * print_string - function that gets string argument,
 * and returns pointer to string argument
 * @v: va_list type to extract string argument
 * Return: lenght of printed string
 */

int print_string(va_list *v)
{
	char *s = va_arg(*v, char *);
	int len = 0;

	if (s != NULL)
	{
		len = _strlen(s);
		print_to(s, 0, len);
	}
	else
	{
		len = 6;
		print_to("(null)", 0, len);
	}

	return (len);
}

/**
 * print_char - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_char(va_list *v)
{
	char s = va_arg(*v, int);

	_putchar(s);

	return (1);
}


/**
 * print_int - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_int(va_list *v)
{
	int i, len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, int);

	len = int_toa(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}

/**
 * print_dec - function that extracts and returns decimal argument
 * @v: va_list type to extract decimal argument
 * Return: lenght of printed string
 */

int print_dec(va_list *v)
{
	return (print_int(v));
}

/**
 * print_double - function that extracts and returns double argument
 * @v: va_list type to extract double argument
 * Return: lenght of printed string
 */

int print_double(va_list *v)
{
	double d = va_arg(*v, double);
	int len;
	char *s = malloc(BUFF_SIZE);

	len = float_toa(s, d, -1);
	print_to(s, 0, len);
	free(s);

	return (len);
}
