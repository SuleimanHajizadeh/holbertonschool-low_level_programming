#include "main.h"

/**
 * print_diagonal - Draws a diagonal line on the terminal using '\'
 * @n: Number of times the character '\' should be printed
 *
 * Description: If n <= 0, prints only a newline.
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			_putchar(' ');

		_putchar('\\');
		_putchar('\n');
	}
}
