#include "main.h"

/**
 * print_triangle - prints a triangle of size 'size'
 * @size: size of the triangle
 *
 * Description: Prints a right-aligned triangle using '#'.
 * If size is 0 or less, prints only a newline.
 */
void print_triangle(int size)
{
	int row, col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			if (col <= size - row)
				_putchar(' ');
			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
