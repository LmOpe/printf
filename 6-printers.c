#include "main.h"
/**
 * print_addr - function that converts and prints a dec as hex
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_addr(va_list *v)
{
	unsigned long int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned long int);

	*s = '0';
	*(s + 1) = 'x';
	len = _itoh(s + 2, i) + 2;
	print_to(s, 0, len);
	free(s);

	return (len);
}


/**
 * print_rev - function that converts and prints a dec as hex
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_rev(va_list *v)
{
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	s = va_arg(*v, char *);

	len = _strlen(s);
	rev_str(s, len);
	printf("got here len %d\n", len);
	print_to(s, 0, len);
	free(s);

	return (len);
}
