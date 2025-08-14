#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - prints a buffer in a formatted hex+ascii view
 * @b: pointer to the buffer
 * @size: number of bytes to print
 */
void print_buffer(char *b, int size)
{
	int i, j, idx;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		/* print offset */
		printf("%08x: ", i);

		/* print hex bytes, two bytes at a time, space separated */
		for (j = 0; j < 10; j += 2)
		{
			idx = i + j;

			/* first byte of the pair */
			if (idx < size)
				printf("%02x", (unsigned char)b[idx]);
			else
				printf("  ");

			/* second byte of the pair */
			if ((idx + 1) < size)
				printf("%02x", (unsigned char)b[idx + 1]);
			else
				printf("  ");

			/* space after each pair */
			printf(" ");
		}

		/* two spaces before ASCII representation */
		printf(" ");

		/* print ASCII (printable) or '.' for non-printable */
		for (j = 0; j < 10; j++)
		{
			idx = i + j;
			if (idx < size)
			{
				if (isprint((unsigned char)b[idx]))
					printf("%c", b[idx]);
				else
					printf(".");
			}
		}

		printf("\n");
	}
}
