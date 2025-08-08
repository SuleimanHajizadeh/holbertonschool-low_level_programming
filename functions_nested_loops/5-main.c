#include "main.h"

/**
 * main - Tests the print_sign function
 *
 * Return: Always 0
 */
int main(void)
{
	int r;

	r = print_sign(98);
	_putchar(',');
	_putchar(' ');
	_putchar(r + '0');
	_putchar('\n');

	r = print_sign(0);
	_putchar(',');
	_putchar(' ');
	_putchar(r + '0');
	_putchar('\n');

	r = print_sign(-42);
	_putchar(',');
	_putchar(' ');
	_putchar((r * -1) + '0');
	_putchar('\n');

	return (0);
}
