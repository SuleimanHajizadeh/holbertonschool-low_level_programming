#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to search in
 * @accept: the string containing allowed characters
 *
 * Return: the number of bytes in the initial segment of s
 *         which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match;
	char *a;

	while (*s)
	{
		match = 0;
		a = accept;

		while (*a)
		{
			if (*s == *a)
			{
				match = 1;
				break;
			}
			a++;
		}

		if (!match)
			break;

		count++;
		s++;
	}

	return (count);
}
