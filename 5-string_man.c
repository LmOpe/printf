#include "main.h"


/**
 * rev_str - function that reverses a string
 * @s: string to rev
 * @len: length of string
 * Return: void
 */

void rev_str(char *s, int len)
{
	int i = 0, tmp;

	len -= 1;
	while ((len - i) > (len / 2))
	{
		tmp = *(s + i);
		*(s + i) = *(s + len - i);
		*(s + len - i) = tmp;
		i++;
	}
}

/**
 * uint_toa - converts unsigned integer to string
 * @dst: pointer to string destination
 * @i: integer to convert
 * Return: length of string
 */

int uint_toa(char *dst, unsigned long int i)
{
	unsigned int tmp = i;
	int c, len;

	c = 0;
	tmp = i;

	while (tmp != 0)
	{
		c++;
		tmp /= 10;
	}
	len = c;
	tmp = i;

	*(dst + c) = '\0';
	c--;

	while (c >= 0)
	{
		*(dst + c) = '0' + tmp % 10;
		tmp /= 10;
		c--;
	}

	return (len);
}

