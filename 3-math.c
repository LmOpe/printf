#include "main.h"

/**
 * _pow - calculates a raised to the power of n
 * @a: number to raise to pwoer of n
 * @n: power
 * Return: a raised to power n
 */

int _pow(int a, int n)
{
	int c, tmp;

	tmp = a;
	if (n == 0)
	return (1);
	for (c = 0; c < n - 1; c++)
	{
		tmp *= a;
	}
	return (tmp);
}

/**
 * _itob - calculates specified base of a decimal
 * @dest: pointer to converted string
 * @a: number to convert to specified base
 * @base: base to be converted
 * Return: lenght of converted string
 */

int _itob(char *dest, unsigned int a, unsigned int base)
{
	unsigned int tmp, len;
	int c;

	tmp = a;
	c = 0;

	while (tmp > 0)
	{
		c++;
		tmp /= base;
	}
	len = c;
	*(dest + c) = '\0';
	c--;
	tmp = a;
	while (c >= 0)
	{
		*(dest + c) = (tmp % base) + '0';
		tmp /= base;
		c--;
	}
	return (len);
}

/**
 * _itoh - calculates hexadecimal of a decimal
 * @dest: pointer to converted string
 * @a: number to convert to hexadecimal
 * Return: length of converted string
 */

int _itoh(char *dest, unsigned int a)
{
	char *s = malloc(sizeof(char) * BUFF_SIZE);
	int c = 0, len = 0, i = 0, b = 0, d = 0;

	len = _itob(s, a, 2);
	c = len;
	while (c > 0)
	{
		i = b = 0;
		while (i < 4 && c > 0)
		{
			if (*(s + c - 1) == '1')
			b += _pow(2, i);
			i++;
			c--;
		}
		if (b < 9)
		*(dest + d) = '0' + b;
		else
		*(dest + d) = 'a' + b - 10;
		d++;
	}
	*(dest + d) = '\0';
	rev_str(dest, d);
	free(s);
	return (d);
}

/**
 * _itoH - calculates hexadecimal of a decimal
 * @dest: pointer to converted string
 * @a: number to convert to hexadecimal
 * Return: length of converted string
 */

int _itoH(char *dest, unsigned int a)
{
	char *s = malloc(sizeof(char) * BUFF_SIZE);
	int c = 0, len = 0, i = 0, b = 0, d = 0;

	len = _itob(s, a, 2);
	c = len;
	while (c > 0)
	{
		i = b = 0;
		while (i < 4 && c > 0)
		{
			if (*(s + c - 1) == '1')
			b += _pow(2, i);
			i++;
			c--;
		}
		if (b < 9)
		*(dest + d) = '0' + b;
		else
		*(dest + d) = 'A' + b - 10;
		d++;
	}
	*(dest + d) = '\0';
	rev_str(dest, d);
	free(s);
	return (d);
}
