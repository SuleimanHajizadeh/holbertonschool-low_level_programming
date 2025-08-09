#include "main.h"

/**
 * times_table - prints the 9 times table starting with 0
 */
void times_table(void)
{
	int a, b, timestable_variable;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			timestable_variable = a * b;
			if (b == 0)
			{
				_putchar(timestable_variable + '0');
			}
			else if (timestable_variable < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(timestable_variable + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar(timestable_variable / 10 + '0');
				_putchar(timestable_variable % 10 + '0');
			}
		}
		_putchar('\n');
	}
}
