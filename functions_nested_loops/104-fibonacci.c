#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with
 * 1 and 2, separated by a comma followed by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	unsigned long fib1 = 1, fib2 = 2, sum;
	unsigned long fib1_h, fib1_l, fib2_h, fib2_l;
	unsigned long half_h, half_l;

	printf("%lu, %lu", fib1, fib2);

	for (count = 3; count <= 92; count++)
	{
		sum = fib1 + fib2;
		printf(", %lu", sum);
		fib1 = fib2;
		fib2 = sum;
	}

	fib1_h = fib1 / 10000000000;
	fib1_l = fib1 % 10000000000;
	fib2_h = fib2 / 10000000000;
	fib2_l = fib2 % 10000000000;

	for (count = 93; count <= 98; count++)
	{
		half_h = fib1_h + fib2_h;
		half_l = fib1_l + fib2_l;
		if (half_l > 9999999999)
		{
			half_h += 1;
			half_l %= 10000000000;
		}
		printf(", %lu%09lu", half_h, half_l);

		fib1_h = fib2_h;
		fib1_l = fib2_l;
		fib2_h = half_h;
		fib2_l = half_l;
	}

	printf("\n");
	return (0);
}
