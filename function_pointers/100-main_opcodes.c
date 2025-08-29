#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, exits with 1 or 2 on error
 */
int main(int argc, char *argv[])
{
	int n, i;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}

	ptr = (unsigned char *)main;
	for (i = 0; i < n; i++)
	{
		printf("%02x", ptr[i]);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
