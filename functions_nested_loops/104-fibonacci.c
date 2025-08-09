#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long fib1_h = 0, fib1_l = 1;
	unsigned long fib2_h = 0, fib2_l = 2;
	unsigned long next_h, next_l;
	int count;

	printf("%lu, %lu", fib1_l, fib2_l);

	for (count = 3; count <= 98; count++)
	{
		/* Next Fibonacci = fib1 + fib2 */
		next_l = fib1_l + fib2_l;
		next_h = fib1_h + fib2_h;
		if (next_l < fib1_l)
			next_h += 1;

		/* Çap et */
		if (next_h == 0)
			printf(", %lu", next_l);
		else
			printf(", %lu%09lu", next_h, next_l);

		/* növbəti ədəd üçün dəyiş */
		fib1_l = fib2_l;
		fib1_h = fib2_h;
		fib2_l = next_l;
		fib2_h = next_h;
	}
	printf("\n");

	return (0);
}
