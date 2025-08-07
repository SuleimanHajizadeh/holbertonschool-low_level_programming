#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all base 16 numbers in lowercase using putchar
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 16)
	{
		if (i < 10)
			putchar(i + '0');
		else
			putchar(i - 10 + 'a');
		i++;
	}
	putchar('\n');

	return (0);
}
