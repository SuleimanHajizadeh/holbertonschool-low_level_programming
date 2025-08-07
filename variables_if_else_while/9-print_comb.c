#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers from 0 to 9
 *              separated by ", " using only putchar and no char variables
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(i + '0');

		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');

	return (0);
}
