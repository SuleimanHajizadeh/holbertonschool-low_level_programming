#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 from 0,
 *              using only putchar and no char type
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(i + 48); /* ASCII of '0' is 48 */
		i++;
	}
	putchar('\n');

	return (0);
}
