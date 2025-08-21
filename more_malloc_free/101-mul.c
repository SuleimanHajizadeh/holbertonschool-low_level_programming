#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Prints a character */
int _putchar(char c)
{
    return putchar(c);
}

/* Multiply two positive numbers as strings and print the result */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, totalLen, i, j, carry, sum;
    int *result;

    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    num1 = argv[1];
    num2 = argv[2];

    /* Check all characters are digits */
    for (i = 0; num1[i]; i++)
        if (!isdigit(num1[i])) { printf("Error\n"); return 98; }
    for (i = 0; num2[i]; i++)
        if (!isdigit(num2[i])) { printf("Error\n"); return 98; }

    len1 = strlen(num1);
    len2 = strlen(num2);
    totalLen = len1 + len2;

    /* Allocate array to hold multiplication result */
    result = calloc(totalLen, sizeof(int));
    if (!result)
        return 98;

    /* Perform multiplication */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            sum = (num1[i]-'0') * (num2[j]-'0') + result[i+j+1] + carry;
            result[i+j+1] = sum % 10;
            carry = sum / 10;
        }
        result[i+j+1] += carry;
    }

    /* Skip leading zeros */
    i = 0;
    while (i < totalLen && result[i] == 0)
        i++;

    /* Print result */
    if (i == totalLen)
        _putchar('0');
    else
        for (; i < totalLen; i++)
            _putchar(result[i] + '0');

    _putchar('\n');
    free(result);
    return 0;
}
