#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Description: This function prints the multiplication table for
 * numbers 0 through 9, with proper formatting so columns align.
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
            else
            {
                _putchar(',');
                _putchar(' ');
                if (timestable_variable < 10)
                    _putchar(' ');
                else
                    _putchar((timestable_variable / 10) + '0');

                _putchar((timestable_variable % 10) + '0');
            }
        }
        _putchar('\n');
    }
}
