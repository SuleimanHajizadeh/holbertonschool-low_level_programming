#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to reverse
 */
void rev_string(char *s)
{
	int len = 0;
	int start = 0;
	int end;
	char temp;

	while (s[len] != '\0')
		len++;

	end = len - 1;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
