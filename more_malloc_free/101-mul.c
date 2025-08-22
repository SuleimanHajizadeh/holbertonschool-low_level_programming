#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * free_and_exit - Frees allocated memory if not NULL, then exits with status 98
 * @ptr: Pointer to free
 *
 * Return: Nothing (program exits)
 */
void free_and_exit(int *ptr)
{
	if (ptr)
		free(ptr);
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_str - Checks if a string is all digits
 * @s: String to check
 *
 * Return: 1 if string is valid, 0 otherwise
 */
int is_digit_str(char *s)
{
	if (!s || *s == '\0')
		return (0);
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * multiply_and_print - Multiplies two large positive integers
 * @num1: First number string
 * @num2: Second number string
 *
 * Return: Nothing
 */
void multiply_and_print(char *num1, char *num2)
{
	size_t len1 = strlen(num1), len2 = strlen(num2);
	size_t len = len1 + len2, i, j;
	int *res, d1, d2, carry, sum;

	res = calloc(len, sizeof(int));
	if (!res)
		free_and_exit(NULL);

	for (i = 0; i < len1; i++)
	{
		d1 = num1[len1 - 1 - i] - '0';
		carry = 0;
		for (j = 0; j < len2; j++)
		{
			d2 = num2[len2 - 1 - j] - '0';
			sum = d1 * d2 + res[len - 1 - (i + j)] + carry;
			res[len - 1 - (i + j)] = sum % 10;
			carry = sum / 10;
		}
		res[len - 1 - (i + j)] += carry;
	}

	/* Skip leading zeros */
	i = 0;
	while (i < len - 1 && res[i] == 0)
		i++;

	for (; i < len; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	if ((argv[1][0] == '0' && argv[1][1] == '\0') ||
	    (argv[2][0] == '0' && argv[2][1] == '\0'))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	multiply_and_print(argv[1], argv[2]);
	return (0);
}