#include "main.h"

/**
 * swap_int - Write a function that swaps the values of two integers
 * &a and &b: change the values of a and b
 */
void swap_int(int *a, int *b)
{
	int address;


	address = *a;
	*a = *b;
	*b = address;
}
