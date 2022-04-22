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
 * _itob - calculates binary of a decimal
 * @dest: pointer to converted string
 * @a: number to convert to binary
 * Return: lenght of converted string
 */

int _itob(char *dest, unsigned int a)
{
	unsigned int tmp, len;
	int c;

	tmp = a;
	c = 0;

	while (tmp > 0)
	{
		c++;
		tmp /= 2;
	}
	len = c;
	*(dest + c) = '\0';
	c--;
	tmp = a;
	while (c >= 0)
	{
		*(dest + c) = (tmp % 2) + '0';
		tmp /= 2;
		c--;
	}
	return (len);
}

