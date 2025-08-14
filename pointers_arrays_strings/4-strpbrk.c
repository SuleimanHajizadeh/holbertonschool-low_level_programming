#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search in
 * @accept: the string containing characters to match
 *
 * Return: pointer to the first byte in s that matches one
 *         of the bytes in accept, or NULL if none is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				return (s);
			a++;
		}
		s++;
	}

	return (0);
}
