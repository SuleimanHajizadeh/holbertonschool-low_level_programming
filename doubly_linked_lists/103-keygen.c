#include <stdio.h>
#include <string.h>

/**
 * main - generates a valid key for crackme5
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    char key[100];
    int i, len;

    if (argc != 2)
        return 1;

    len = strlen(argv[1]);
    for (i = 0; i < len; i++)
        key[i] = argv[1][i] + len;  /* transform username to key */

    key[len] = '\0';  /* NO newline */
    printf("%s", key); /* NO newline */
    return 0;
}
