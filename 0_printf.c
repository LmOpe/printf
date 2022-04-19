#include "main.h"

/**
 * _printf - function that prints output according to format
 * @format: string that determines the conversion,
 * specifiers.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int spec_count, c, n, start, end, len, pos, prev;
	int (*funcs[6])(va_list *) = 
	{print_char, print_string, print_dec, print_int, print_double, print_perct};

	va_start(vl, format);

	spec_count = count_specifiers(format);

	c = n = start = len = 0;
	while (n >= 0)
	{
		n = search_spec(format, n);

		if (n > 0)
		{
			if (prev > 0)
			start = prev + 1;
			end = n - 1;
			len += print_to(format, start, end);
			pos = valid_spec(*(format + n));
			len += funcs[pos](&vl);
		}
		else
		len += print_to(format, prev + 1, _strlen(format));

		prev = n;

	}
	va_end(vl);
	printf("total length is %d\n", len);
	return (len);
}

/**
 * count_specifiers - function that counts and returns the numbers,
 * of specifiers found.
 * @s: string to count specifiers
 * Return: the number of specifiers found
 */

int count_specifiers(const char *s)
{
	int n = 0, c = 0;

	while (n != -1)
	{
		n = search_spec(s, n);
		if (n > 0)
		c++;
	}

	return (c);
}


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
 * get_specifiers - function that extract specifiers and return,
 * the specifier types.
 * @s: string to extract specifiers
 * @n: number of specifiers
 * @dst: pointer to string destination
 * Return: void
 */

void get_specifiers(const char *s, int n, char *dst)
{
	int c, d = 0;

	for (c = 0; c < n; c++)
	{
		d = search_spec(s, d);
		*(dst + c) = *(s + d);
	}
	*(dst + c) = '\0';
}

/**
 * int_toa - converts integer to string
 * @dst: pointer to string destination
 * @i: integer to convert
 * Return: length of string
 */

int int_toa(char *dst, int i)
{
	int tmp = i, c, len;

	c = 0;
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

/**
 * _pow - calculates a raised to power of n
 * @a: number to raise to power of n
 * @n: power
 * Return: a raised to power n
 */

int _pow(int a, int n)
{
	int c, tmp;

	tmp = a;
	if (n == 0)
	return 1;
	for (c = 0; c < n - 1; c++)
	{
		tmp *= a;
	}
	
	return (tmp);
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
	int tmp, c, len;

	if (precision < 0)
	precision = 4;
	tmp = (int) f;
	len = int_toa(dst, tmp);
	tmp = (int) ((f - (double) tmp) * _pow(10, precision));
	*(dst + len) = '.';
	len += int_toa((dst + len + 1), tmp);
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
	
	while(*(s + len) != '\0')
	{
		len ++;
	}
	return (len);
}


/**
 * print_string - function that gets string argument,
 * and returns pointer to string argument
 * @v: va_list type to extract string argument
 * Return: lenght of printed string
 */

int print_string(va_list *v)
{
	char *s = va_arg(*v, char *);
	int len;

	len = _strlen(s);
	print_to(s, 0, len);
	free(s);

	return (len);
}

/**
 * print_char - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_char(va_list *v)
{
	char s = va_arg(*v, int );

	_putchar(s);

	return (1);
}

/**
 * print_perct - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_perct(va_list *v)
{
	_putchar('%');

	return (1);
}

/**
 * print_int - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_int(va_list *v)
{
	int i, len;
	char *s = malloc(sizeof(char) * BUFF_SIZE);

	i = va_arg(*v, int);

	len = int_toa(s, i);
	print_to(s, 0, len);
	free(s);

	return (len);
}

/**
 * print_dec - function that extracts and returns decimal argument
 * @v: va_list type to extract decimal argument
 * Return: lenght of printed string
 */

int print_dec(va_list *v)
{
	return (print_int(v));
}

/**
 * print_double - function that extracts and returns double argument
 * @v: va_list type to extract double argument
 * @precision: precision of floating number
 * Return: lenght of printed string
 */

int print_double(va_list *v)
{
	double d = va_arg(*v, double);
	int len;
	char *s = malloc(BUFF_SIZE);

	len = float_toa(s, d, 4);
	print_to(s, 0, len);
	free(s);

	return (len);
}

/**
 * valid_spec - function that checks if c is a valid specifier
 * @c: character to search
 * Return: 1 or -1
 */

int valid_spec(char c)
{
	char *s = VAL_SPEC;
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		return (i);
		i++;
	}
	return (-1);
}

