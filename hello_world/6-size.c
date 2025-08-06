#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the size of various C data types using sizeof.
 * The output will vary depending on the architecture (32-bit vs 64-bit).
 * This program helps to understand memory allocation for types like
 * char, int, long int, long long int, and float.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char Suleyman;
	int one;
	long int tvelve;
	long long int one_hundred_tvelve;
	float one_point_five;

	printf("Size of a char: %lu byte(s)\n", sizeof(Suleyman));
	printf("Size of an int: %lu byte(s)\n", sizeof(one));
	printf("Size of a long int: %lu byte(s)\n", sizeof(tvelve));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(one_hundred_tvelve));
	printf("Size of a float: %lu byte(s)\n", sizeof(one_point_five));

	return (0);
}
