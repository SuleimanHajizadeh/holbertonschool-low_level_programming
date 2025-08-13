#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: 0 on success
 *
 * Idea:
 *  - The crackme accepts any sequence of bytes whose sum is 2772.
 *  - We keep emitting random bytes (0..127) while keeping the running sum ≤ 2772.
 *  - The last byte is chosen so that the total sum is exactly 2772.
 */
int main(void)
{
	int sum = 0;
	int byte;

	srand((unsigned int)time(NULL));

	/* Keep adding random bytes as long as we don't overshoot 2772 */
	while (sum < 2772)
	{
		/* Random byte in [0, 127] */
		byte = rand() % 128;

		/* If this exact byte would overshoot, force the exact remainder and finish */
		if (sum + byte > 2772)
			byte = 2772 - sum;

		putchar(byte);
		sum += byte;

		if (sum == 2772)
			break;
	}

	return (0);
}
