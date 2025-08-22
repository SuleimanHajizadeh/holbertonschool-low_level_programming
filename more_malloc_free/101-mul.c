#include "main.h"
#include <stdlib.h>

/**
 * _strlen - get string length
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
 * _isdigit_str - 1 if only digits, else 0
 * @s: string
 * Return: 1 if digits only, 0 otherwise
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
 * _puts - print a string using _putchar
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
 * print_zero_nl - print "0\n"
 */
static void print_zero_nl(void)
{
	_putchar('0');
	_putchar('\n');
}

/**
 * mul_print - multiply two positive integer strings and print
 * @a: first number (digits only)
 * @b: second number (digits only)
 */
static void mul_print(char *a, char *b)
{
	int len1 = _strlen(a), len2 = _strlen(b);
	int n = len1 + len2, i, j, start = 0;
	int *res;

	/* quick zero checks */
	while (start < len1 && a[start] == '0')
		start++;
	if (start == len1)
	{
		print_zero_nl();
		return;
	}
	start = 0;
	while (start < len2 && b[start] == '0')
		start++;
	if (start == len2)
	{
		print_zero_nl();
		return;
	}

	res = (int *)malloc(sizeof(int) * n);
	if (!res)
		error_exit();

	for (i = 0; i < n; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		int da = a[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			int db = b[j] - '0';
			int pos = i + j + 1;
			int sum = da * db + res[pos];

			res[pos] = sum % 10;
			res[pos - 1] += sum / 10;
		}
	}

	start = 0;
	while (start < n && res[start] == 0)
		start++;

	if (start == n)
	{
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
 * main - multiply two positive numbers
 * @ac: arg count
 * @av: arg vector
 * Return: 0 on success (exits 98 on error)
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
