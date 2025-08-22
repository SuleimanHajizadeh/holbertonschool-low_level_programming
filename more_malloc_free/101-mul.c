#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/* Function prototypes */
int _isdigit(char *s);
int _strlen(char *s);
void _error(int *res);
void multiply(char *num1, char *num2);

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		_error(NULL);

	multiply(argv[1], argv[2]);
	return (0);
}

/**
 * _isdigit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _error - prints "Error" and exits with status 98
 * @res: pointer to allocated memory to free, NULL if none
 */
void _error(int *res)
{
	if (res)
		free(res);

	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two numbers given as strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *res;
	int i, j, carry, n1, n2, sum, start;

	res = calloc(len1 + len2, sizeof(int));
	if (!res)
		_error(NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + res[i + j + 1] + carry;
			carry = sum / 10;
			res[i + j + 1] = sum % 10;
		}
		res[i + j + 1] += carry;
	}

	start = 0;
	while (start < (len1 + len2) && res[start] == 0)
	{
		start++;
	}

	if (start == len1 + len2)
	{
		_putchar('0');
	}
	else
	{
		for (; start < len1 + len2; start++)
		{
			_putchar(res[start] + '0');
		}
	}

	_putchar('\n');
	free(res);
}
