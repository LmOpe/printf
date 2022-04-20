#include "main.h"

/**
 * print_bin - function that converts and prints a dec as bin
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_bin(va_list *v)
{
	int i, len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, int);

	len = _itob(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}

