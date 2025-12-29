#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _print - prints result and frees memory
 * @str: result string
 * @l: length
 */
void _print(char *str, int l)
{
	int i, started = 0;

	for (i = 0; i < l; i++)
	{
		if (str[i] != '0')
			started = 1;
		if (started || i == l - 1)
			_putchar(str[i]);
	}
	_putchar('\n');
	free(str);
}

/**
 * mul - multiplies a digit with a number string
 * @n: digit char
 * @num: number string
 * @num_index: last index of num
 * @dest: destination buffer
 * @dest_index: start index in dest
 *
 * Return: dest or NULL on overflow
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int j, k, mul, mulrem = 0, add, addrem = 0;

	for (j = num_index, k = dest_index; j >= 0; j--, k--)
	{
		mul = (n - '0') * (num[j] - '0') + mulrem;
		mulrem = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[k] = (add % 10) + '0';
	}

	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
		add = (dest[k] - '0') + addrem;
		addrem = add / 10;
		dest[k] = (add % 10) + '0';
	}

	if (addrem)
		return (NULL);

	return (dest);
}

/**
 * check_for_digits - checks if args are digits
 * @av: arguments
 *
 * Return: 0 if valid, 1 if not
 */
int check_for_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
		for (j = 0; av[i][j]; j++)
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
	return (0);
}

/**
 * init - initializes string with zeros
 * @str: string
 * @l: length
 */
void init(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - multiplies two numbers
 */
int main(int argc, char *argv[])
{
	int l1, l2, ln, i, ti;
	char *a;
	char e[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}

	for (l1 = 0; argv[1][l1]; l1++)
		;
	for (l2 = 0; argv[2][l2]; l2++)
		;

	ln = l1 + l2 + 1;
	a = malloc(sizeof(char) * ln);
	if (!a)
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}

	init(a, ln - 1);

	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
	{
		if (!mul(argv[2][ti], argv[1], l1 - 1, a, ln - 2 - i))
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			free(a);
			exit(98);
		}
	}

	_print(a, ln - 1);
	return (0);
}
