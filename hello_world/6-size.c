#include <stdio.h>
/**
 * main - prints a specific sentence using puts
 *
 * Return:  Always 0 (success)
 */
int main(void)
{
	char Suleyman;
	int one;
	long int tvelve;
	long long int one_hundred_tvelve;
	float one_point_five;
	printf("Size of a char: %lu byte(s)\n", sizeof (Suleyman));
	printf("Size of an int: %lu byte(s)\n", sizeof (one));
	printf("Size of a long int: %lu byte(s)\n", sizeof (tvelve));
	printf("Size of a long long int: %lu byte(s)\n", sizeof (one_hundred_tvelve));
	printf("Size of a float: %lu byte(s)\n", sizeof (one_point_five));
	return (0);
}
