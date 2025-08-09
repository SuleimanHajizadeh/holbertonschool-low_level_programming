#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The times table number to print
 *
 * Description: Only prints the table if 0 <= n <= 15.
 * The table is formatted so that columns align properly.
 */
void print_times_table(int n)
{
	int row, col, prod;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			prod = row * col;

			if (col == 0)
				printf("%d", prod);
			else
				printf("%4d", prod);

			if (col != n)
				printf(",");
		}
		printf("\n");
	}
}
