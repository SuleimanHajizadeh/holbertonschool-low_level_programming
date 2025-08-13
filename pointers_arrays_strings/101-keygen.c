#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a printable random valid password for 101-crackme
 *
 * Return: 0 on success
 */
int main(void)
{
	int sum = 0, byte;

	srand((unsigned int)time(NULL));

	while (sum < 2772)
	{
		/* printable ASCII range: 33 (!) to 126 (~) */
		byte = (rand() % 94) + 33;

		if (sum + byte > 2772)
			byte = 2772 - sum;

		putchar(byte);
		sum += byte;

		if (sum == 2772)
			break;
	}

	return (0);
}
