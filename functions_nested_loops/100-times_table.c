#include "main.h"

/**
 * print_number - prints an integer (0-225) using _putchar
 * @n: integer to print
 */
void print_number(int n)
{
	if (n >= 100)
		_putchar((n / 100) + '0');
	if (n >= 10)
		_putchar(((n / 10) % 10) + '0');
	_putchar((n % 10) + '0');
}

/**
 * print_times_table - prints the n times table, starting from 0
 * @n: times table size (0 <= n <= 15)
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
			{
				print_number(prod);
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (prod < 10)
				{
					_putchar(' ');
					_putchar(' ');
					print_number(prod);
				}
				else if (prod < 100)
				{
					_putchar(' ');
					print_number(prod);
				}
				else
					print_number(prod);
			}
		}
		_putchar('\n');
	}
}
