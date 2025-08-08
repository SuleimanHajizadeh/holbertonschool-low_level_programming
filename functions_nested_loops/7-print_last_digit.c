#include "main.h"

/**
 * print_last_digit - prints and returns the last digit of a number
 * @n: the number to process
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int last_digit;

	last_digit = _abs(n % 10); /* get last digit and make it positive */
	_putchar(last_digit + '0'); /* convert digit to char and print */
	return (last_digit);
}
