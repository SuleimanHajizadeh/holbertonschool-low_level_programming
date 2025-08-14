#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int new_word = 1; /* Flag to detect start of a word */
	char sep[] = " \t\n,;.!?\"(){}";
	int j;

	while (str[i] != '\0')
	{
		/* Check if current char is a separator */
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j])
			{
				new_word = 1;
				break;
			}
		}

		/* If it's a word start and it's lowercase, capitalize it */
		if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
			new_word = 0;
		}
		else if (j == 0 || sep[j] == '\0')
		{
			/* Inside a word */
			new_word = 0;
		}

		i++;
	}
	return (str);
}
