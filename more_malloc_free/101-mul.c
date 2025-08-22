#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * print_error - Prints "Error" followed by a new line and exits with status 98
 *
 * Return: Nothing (program exits)
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_str - Checks if a string consists of only digits
 * @s: The string to check
 *
 * Return: 1 if string is valid (all digits), 0 otherwise
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
 * multiply_and_print - Multiplies two positive numbers given as strings
 * @num1: First number as a string
 * @num2: Second number as a string
 *
 * Description:
 * Uses the grade-school multiplication algorithm to handle arbitrarily
 * large positive integers and prints the result.
 *
 * Return: Nothing
 */
void multiply_and_print(char *num1, char *num2)
{
	size_t len1 = strlen(num1), len2 = strlen(num2), len = len1 + len2;
	int *res;
	size_t i, j;

	res = calloc(len, sizeof(int));
	if (res == NULL)
		print_error();

	for (i = 0; i < len1; i++)
	{
		int d1 = num1[len1 - 1 - i] - '0';
		int carry = 0;

		for (j = 0; j < len2; j++)
		{
			int d2 = num2[len2 - 1 - j] - '0';
			int sum = d1 * d2 + res[len - 1 - (i + j)] + carry;

			res[len - 1 - (i + j)] = sum % 10;
			carry = sum / 10;
		}
		res[len - 1 - (i + j)] += carry;
	}

	i = 0;
	while (i < len - 1 && res[i] == 0)
		i++;

	for (; i < len; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
}

/**
 * main - Entry point for program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error();

	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
		print_error();

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