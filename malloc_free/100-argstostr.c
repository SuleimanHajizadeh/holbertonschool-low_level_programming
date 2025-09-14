#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, or NULL on failure
 *         each argument followed by '\n'
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			continue;
		for (j = 0; av[i][j]; j++)
			total_len++;
		total_len++; /* for '\n' */
	}

	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			continue;
		for (j = 0; av[i][j]; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
