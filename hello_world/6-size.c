#include <stdio.h>

int main(void)
{
	printf("%lu\n", sizeof(...));
	return (0);
}
/**
 * main - Entry point of the program
 *
 * Description: This program prints the line:
 * "Size",
 * followed by a new line. It uses the puts function and
 * returns 0 upon successful completion.
 *
 * Return: Always 0 (Success)
 */
