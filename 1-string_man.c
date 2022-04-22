#include "main.h"


/**
 * print_to - function that prints from start to end of format
 * @s: string to print
 * @start: start position
 * @end: end position
 * Return: Length of printed string
 */

int print_to(const char *s, int start, int end)
{
	int c, len;

	len = end - start;
	for (c = start; c < end; c++)
	{
		_putchar(*(s + c));
	}

	return (len);
}

/**
 * search_spec - function that gets position of next,
 * specifier found.
 * @s: string to search specifiers
 * @n: search start position
 * Return: the number of specifiers found
 */

int search_spec(const char *s, int n)
{
	int c;

	c = n;
	while (*(s + c) != '\0')
	{
		if (*(s + c) == '%')
		{
			if (valid_spec(*(s + c + 1)) >= 0)
			return (c + 1);
		}
		c++;
	}
	return (-1);
}


/**
 * int_toa - converts integer to string
 * @dst: pointer to string destination
 * @i: integer to convert
 * Return: length of string
 */

int int_toa(char *dst, int i)
{
	int tmp = i, tmp2, c, len, sen;

	c = sen = 0;
	if (tmp < 0)
	{
		*(dst + c) = '-';
		tmp = tmp * -1;
		c++;
		sen = 1;
	}
	tmp2 = tmp;

	while (tmp2 != 0)
	{
		c++;
		tmp2 /= 10;
	}
	len = c;
	tmp2 = tmp;

	*(dst + c) = '\0';
	c--;

	while (c >= sen)
	{
		*(dst + c) = '0' + tmp2 % 10;
		tmp2 /= 10;
		c--;
	}

	return (len);
}


/**
 * float_toa - converts integer to string
 * @dst: pointer to string destination
 * @f: float to convert
 * @precision: precision of float
 * Return: void
 */

int float_toa(char *dst, double f, int precision)
{
	int tmp, len;

	if (precision < 0)
	precision = 1;
	tmp = (int) f;
	len = int_toa(dst, tmp);
	tmp = (int) ((f - (double) tmp) * _pow(10, precision));
	if (tmp < 0)
	{
		tmp *= -1;
	}
	*(dst + len) = '.';
	len++;
	len += int_toa((dst + len), tmp);
	return (len);

}


/**
 * _strlen - Returns the length of a string s
 * @s: pointer to string to find length
 * Return: length of string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}
