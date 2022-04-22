#include "main.h"

/**
 * print_bin - function that converts and prints a dec as bin
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_bin(va_list *v)
{
	unsigned int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned int);

	len = _itob(s, i, 2);
	print_to(s, 0, len);
	free(s);

	return (len);
}


/**
 * print_hex - function that converts and prints a dec as hex
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_hex(va_list *v)
{
	unsigned int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned int);

	len = _itoh(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}


/**
 * print_Hex - function that converts and prints a dec as hex
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_Hex(va_list *v)
{
	unsigned int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned int);

	len = _itoH(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}


/**
 * print_oct - function that converts and prints a dec as oct
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_oct(va_list *v)
{
	unsigned int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned int);

	len = _itob(s, i, 8);
	print_to(s, 0, len);
	free(s);

	return (len);
}


/**
 * print_uint - function that converts and prints a dec as uint
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_uint(va_list *v)
{
	unsigned int i;
	int len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, unsigned int);

	len = uint_toa(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}
