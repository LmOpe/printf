#include "main.h"

/**
 * print_bin - function that converts and prints a dec as bin
 * @v1: va_list type to extract char argument
 * @v2: copy of v1
 * Return: lenght of printed string
 */

int print_bin(va_list *v1, va_list *v2)
{
	int i1, i2, len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i1 = va_arg(*v1, int);
	i2 = va_arg(*v2, int);

	len = _itob(s, i1);
	print_to(s, 0, len);
	free(s);

	return (len);
}

