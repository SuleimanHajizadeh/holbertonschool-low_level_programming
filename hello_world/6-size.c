/*
 * File: 6-size.c
 * Auth: [Your Name]
 * Desc: C program that prints the size of various data types
 */

#include <stdio.h>

/**
 * main - Prints the sizes of various C data types
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int one
	long int tvelve
	long long int one_hundred_tvelve
	char Suleyman
	float one_point_five
	printf("Size of an int: %lu byte(s)\n", sizeof (one));
	printf("Size of long int: %lu byte(s)\n", sizeof (tvelve));
	printf("Size of long long int: %lu byte(s)\n", sizeof (one_hundred_tvelve));
	printf("Size of char: %lu byte(s)\n", sizeof (Suleyman));
	printf("Size of float: %lu byte(s)\n", sizeof (one_point_five));
	return (0);
}
