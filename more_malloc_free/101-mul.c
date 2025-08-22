#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * print_error - prints "Error" and exits with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_str - check if a string is composed only of digits
 * @s: input string
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit_str(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!isdigit((unsigned char)s[i]))
			return (0);
	}
	return (1);
}

/**
 * multiply - multiply two numbers represented as strings
 * @num1: first number (string)
 * @num2: second number (string)
 * Return: result as a string (caller must free)
 */
char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *res = calloc(len1 + len2, sizeof(int));
	char *result;
	int i, j, carry, prod, k, start;

	if (!res)
		return (NULL);

	/* Perform multiplication like on paper */
	for (i = len1 - 1; i >= 0; i--)
	{
		if (!isdigit((unsigned char)num1[i]))
			return (free(res), NULL);
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!isdigit((unsigned char)num2[j]))
				return (free(res), NULL);
			prod = (num1[i] - '0') * (num2[j] - '0');
			carry = prod + res[i + j + 1];
			res[i + j + 1] = carry % 10;
			res[i + j] += carry / 10;
		}
	}

	/* Skip leading zeros */
	start = 0;
	while (start < len1 + len2 && res[start] == 0)
		start++;

	/* If result is 0 */
	if (start == len1 + len2)
	{
		result = malloc(2);
		if (!result)
			return (free(res), NULL);
		result[0] = '0';
		result[1] = '\0';
		free(res);
		return (result);
	}

	/* Convert int array to string */
	result = malloc(len1 + len2 - start + 1);
	if (!result)
		return (free(res), NULL);

	for (k = 0; start < len1 + len2; start++, k++)
		result[k] = res[start] + '0';
	result[k] = '\0';

	free(res);
	return (result);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *res;

	if (argc != 3)
		print_error();
	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
		print_error();

	res = multiply(argv[1], argv[2]);
	if (!res)
		print_error();

	printf("%s\n", res);
	free(res);
	return (0);
}
