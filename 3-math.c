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
