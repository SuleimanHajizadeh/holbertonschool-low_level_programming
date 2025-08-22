#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _isdigit - checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int _isdigit(char *s)
{
	if (*s == '0')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * create_x_array - creates an array of chars and initializes it with 'x'.
 * @size: The size of the array to create.
 *
 * Return: A pointer to the newly created array.
 */
void *create_x_array(int size)
{
	char *array;
	int i = 0;

	array = malloc(sizeof(char) * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = 'x';
		i++;
	}
	return (array);
}

/**
 * main - multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *res;
	int len1, len2, total_len, i, j, k, n1, n2, mul, carry;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	total_len = len1 + len2;

	res = create_x_array(total_len);
	if (!res)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	for (i = 0; i < total_len; i++)
		res[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			mul = n1 * n2 + (res[i + j + 1] - '0') + carry;
			res[i + j + 1] = (mul % 10) + '0';
			carry = mul / 10;
		}
		res[i + j + 1] = (carry % 10) + '0';
	}

	k = 0;
	while (res[k] == '0' && k < total_len - 1)
		k++;

	while (k < total_len)
	{
		_putchar(res[k]);
		k++;
	}
	_putchar('\n');

	free(res);
	return (0);
}