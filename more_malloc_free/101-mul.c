#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int is_digit(char *str);
void errors(void);

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *str1, *str2;
    int length1, length2, length, i, carry, digit1, digit2, *result, a = 0;

    if (argc != 3)
    {
        printf("Error\n");
        exit (98);
    }

    str1 = argv[1];
    str2 = argv[2];

    if (!is_digit(str1) || !is_digit(str2))
    {
        printf("Error\n");
        return (98);
    }

    length1 = _strlen(str1);
    length2 = _strlen(str2);
    length = length1 + length2 + 1;

    result = malloc(sizeof(int) * length);
    if (!result)
        return (1);

    for (i = 0; i <= length1 + length2; i++)
        result[i] = 0;

    for (length1 = _strlen(str1) - 1; length1 >= 0; length1--)
    {
        digit1 = str1[length1] - '0';
        carry = 0;
        for (length2 = _strlen(str2) - 1; length2 >= 0; length2--)
        {
            digit2 = str2[length2] - '0';
            carry += result[length1 + length2 + 1] + (digit1 * digit2);
            result[length1 + length2 + 1] = carry % 10;
            carry /= 10;
        }
        if (carry > 0)
            result[length1 + length2 + 1] += carry;
    }

    for (i = 0; i < length - 1; i++)
    {
        if (result[i])
            a = 1;
        if (a)
            _putchar(result[i] + '0');
    }

    if (!a)
        _putchar('0');
    _putchar('\n');

    free(result);
    return (0);
}

/**
 * is_digit - checks if a string contains only digits
 * @str: string
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
