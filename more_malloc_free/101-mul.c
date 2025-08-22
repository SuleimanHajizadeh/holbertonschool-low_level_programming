#include "main.h"
#include <stdlib.h>

/**
 * _strlen - returns length of a string
 * @s: string
 * Return: length
 */
static int _strlen(char *s)
{
	int l = 0;

	while (s && s[l])
		l++;
	return (l);
}

/**
 * _isdigit_str - checks if s contains only digits
 * @s: string
 * Return: 1 if only digits, 0 otherwise
 */
static int _isdigit_str(char *s)
{
	int i = 0;

	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _puts - print a C-string with _putchar
 * @s: string
 */
static void _puts(char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * error_exit - print "Error" and exit 98
 */
static void error_exit(void)
{
	_puts("Error\n");
	exit(98);
}

/**
 * print_zero_nl - prints "0\n"
 */
static void print_zero_nl(void)
{
	_putchar('0');
	_putchar('\n');
}

/**
 * mul_print - multiply two positive integer strings and print result
 * @a: num1 (digits only)
 * @b: num2 (digits only)
 *
 * Uses long multiplication into an int array, then prints digits with _putchar.
 * Frees all allocated memory before returning.
 */
static void mul_print(char *a, char *b)
{
	int len1 = _strlen(a), len2 = _strlen(b);
	int i, j, n = len1 + len2, start = 0;
	int *res;

	/* handle leading zeros quickly */
	while (start < len1 && a[start] == '0')
		start++;
	if (start == len1) /* a is zero */
	{
		print_zero_nl();
		return;
	}
	start = 0;
	while (start < len2 && b[start] == '0')
		start++;
	if (start == len2) /* b is zero */
	{
		print_zero_nl();
		return;
	}

	res = (int *)malloc(sizeof(int) * n);
	if (!res)
		error_exit();

	/* zero-initialize result buffer */
	for (i = 0; i < n; i++)
		res[i] = 0;

	/* long multiplication from right to left */
	for (i = len1 - 1; i >= 0; i--)
	{
		int da = a[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			int db = b[j] - '0';
			int pos_low = i + j + 1;
			int pos_high = i + j;
			int sum = da * db + res[pos_low];

			res[pos_low] = sum % 10;
			res[pos_high] += sum / 10;
		}
	}

	/* skip leading zeros in result */
	start = 0;
	while (start < n && res[start] == 0)
		start++;

	/* print result digits */
	if (start == n)
	{
		/* should not happen due to earlier zero checks, but safe-guard */
		print_zero_nl();
		free(res);
		return;
	}
	for (i = start; i < n; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
}

/**
 * main - multiply two positive numbers given as strings
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, 98 on error (through exit)
 */
int main(int ac, char **av)
{
	if (ac != 3)
		error_exit();
	if (!_isdigit_str(av[1]) || !_isdigit_str(av[2]))
		error_exit();

	mul_print(av[1], av[2]);
	return (0);
}
