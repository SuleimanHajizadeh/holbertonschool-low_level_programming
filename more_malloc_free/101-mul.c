#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 * Return: length of string
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

/**
 * multiply - multiplies two positive numbers
 * @num1: first number as string
 * @num2: second number as string
 */
void multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int total_len = len1 + len2;
    int i, j, carry, product;
    char *result;

    /* Allocate memory for result (plus null terminator) */
    result = malloc(sizeof(char) * (total_len + 1));
    if (result == NULL)
        exit(98);

    /* Initialize result with zeros */
    for (i = 0; i < total_len; i++)
        result[i] = '0';
    result[total_len] = '\0';

    /* Perform multiplication */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            product = (num1[i] - '0') * (num2[j] - '0');
            product += (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }

    /* Skip leading zeros */
    i = 0;
    while (result[i] == '0' && result[i + 1] != '\0')
        i++;

    print_number(result + i);
    free(result);
}

/**
 * print_number - prints a number string
 * @num: number string to print
 */
void print_number(char *num)
{
    int i = 0;

    while (num[i])
    {
        _putchar(num[i]);
        i++;
    }
    _putchar('\n');
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        print_number("Error");
        exit(98);
    }

    if (!is_digit(argv[1]) || !is_digit(argv[2]))
    {
        print_number("Error");
        exit(98);
    }

    multiply(argv[1], argv[2]);

    return (0);
}