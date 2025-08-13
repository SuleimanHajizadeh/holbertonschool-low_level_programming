#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer value
 */
int _atoi(char *s)
{
	int sign = 1, result = 0, digit;
	int started = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			digit = *s - '0';
			if (!started)
				started = 1;

			/* Build result as negative to avoid overflow */
			if (result < (INT_MIN + digit) / 10)
				return (sign == 1 ? INT_MAX : INT_MIN);
			result = result * 10 - digit;
		}
		else if (started)
			break;
		s++;
	}

	return (sign == 1 ? -result : result);
}
