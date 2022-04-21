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

int _itob(char *dest, int a)
{
	int c, tmp, tmp2, len, sen;

	tmp = a;
	c = sen = 0;
	if (tmp < 0)
	{
		*(dest + c) = '-';
		tmp = tmp * -1;
		c++;
		sen = 1;
	}
	tmp2 = tmp;
	while (tmp2 > 0)
	{
		c++;
		tmp2 /= 2;
	}
	len = c;
	*(dest + c) = '\0';
	c--;
	tmp2 = tmp;
	while (c >= sen)
	{
		*(dest + c) = (tmp2 % 2) + '0';
		tmp2 /= 2;
		c--;
	}
	return (len);
}

