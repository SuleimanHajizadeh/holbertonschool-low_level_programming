#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_hex - prints up to 10 bytes in hex format
 * @b: pointer to buffer
 * @start: starting index
 * @size: total size of buffer
 */
void print_hex(char *b, int start, int size)
{
	int j, idx;

	for (j = 0; j < 10; j += 2)
	{
		idx = start + j;
		if (idx < size)
			printf("%02x", (unsigned char)b[idx]);
		else
			printf("  ");
		if ((idx + 1) < size)
			printf("%02x", (unsigned char)b[idx + 1]);
		else
			printf("  ");
		if (j != 8)
			printf(" ");
	}
}

/**
 * print_ascii - prints up to 10 bytes as ASCII or '.'
 * @b: pointer to buffer
 * @start: starting index
 * @size: total size of buffer
 */
void print_ascii(char *b, int start, int size)
{
	int j, idx;

	for (j = 0; j < 10; j++)
	{
		idx = start + j;
		if (idx < size)
		{
			if (isprint((unsigned char)b[idx]))
				printf("%c", b[idx]);
			else
				printf(".");
		}
	}
}

/**
 * print_buffer - prints a buffer in hex and ASCII
 * @b: pointer to buffer
 * @size: number of bytes to print
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		print_hex(b, i, size);
		printf(" ");
		print_ascii(b, i, size);
		printf("\n");
	}
}
