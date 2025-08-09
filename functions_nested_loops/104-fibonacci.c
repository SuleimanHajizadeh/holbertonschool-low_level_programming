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
	unsigned long fib1_half1, fib1_half2, fib2_half1, fib2_half2;
	unsigned long half1, half2;

	/* İlk 92 Fibonacci ədədi (64-bit dəyişənlərdə rahat saxlanır) */
	printf("%lu, %lu", fib1, fib2);
	for (count = 3; count <= 92; count++)
	{
		sum = fib1 + fib2;
		printf(", %lu", sum);
		fib1 = fib2;
		fib2 = sum;
	}

	/* Böyük Fibonacci ədədləri üçün ədədi hissələrə ayır */
	fib1_half1 = fib1 / 10000000000;
	fib1_half2 = fib1 % 10000000000;
	fib2_half1 = fib2 / 10000000000;
	fib2_half2 = fib2 % 10000000000;

	/* Sonrakı 6 Fibonacci ədədini iki hissə kimi hesabla */
	for (count = 93; count <= 98; count++)
	{
		half1 = fib1_half1 + fib2_half1;
		half2 = fib1_half2 + fib2_half2;
		if (half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}

		printf(", %lu%09lu", half1, half2);

		fib1_half1 = fib2_half1;
		fib1_half2 = fib2_half2;
		fib2_half1 = half1;
		fib2_half2 = half2;
	}
	printf("\n");

	return (0);
}
