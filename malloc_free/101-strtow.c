#include <stdlib.h>
#include "main.h"

/**
 * word_count - counts the number of words in a string
 * @str: input string
 *
 * Return: number of words
 */
static int word_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if ((i == 0 && str[i] != ' ') ||
		    (str[i] != ' ' && str[i - 1] == ' '))
			count++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j = 0, k = 0, w_count, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	w_count = word_count(str);
	if (w_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (w_count + 1));
	if (words == NULL)
		return (NULL);

	while (str[i] && k < w_count)
	{
		while (str[i] == ' ')
			i++;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		end = i;

		words[k] = malloc(sizeof(char) * (end - start + 1));
		if (words[k] == NULL)
		{
			while (k-- > 0)
				free(words[k]);
