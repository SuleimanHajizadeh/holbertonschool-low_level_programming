#include "main.h"

/**
 * str_len - returns length of string
 * @s: string
 *
 * Return: length
 */
int str_len(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * reverse_string - reverses a string in place
 * @r: string to reverse
 * @len: length of the string
 */
void reverse_string(char *r, int len)
{
	int i, j;
	char tmp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = r[i];

		r[i] = r[j];
		r[j] = tmp;
	}
}

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result, or 0 if result cannot fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k = 0, carry = 0, sum = 0;
	int len1 = str_len(n1), len2 = str_len(n2);

	if (size_r <= ((len1 > len2 ? len1 : len2) + 1))
		return (0);

	i = len1 - 1;
	j = len2 - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		if (k >= size_r - 1)
			return (0);

		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}

	r[k] = '\0';
	reverse_string(r, k);

	return (r);
}
