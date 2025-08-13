#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: destination buffer (must be large enough)
 * @src: source string to append to dest
 * @n: maximum number of bytes to take from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* find end of dest */
	while (dest[i] != '\0')
		i++;

	/* copy at most n bytes from src */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* null-terminate */
	dest[i] = '\0';

	return (dest);
}
