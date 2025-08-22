#include "main.h"
#include <stdlib.h>

/**
 * _puts - prints a string using _putchar
 * @s: string
 */
void _puts(char *s)
{
    while (*s)
    {
        _putchar(*s);
        s++;
    }
}

/**
 * errors - prints "Error" and exits with 98
 */
void errors(void)
{
    _puts("Error\n");
    exit(98);
}

/**
 * is_digit - checks if string contains only digits
 * @s: string
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
 * _strlen - returns string length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, len, i, carry, n1, n2, *result, a, b;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        errors();

    num1 = argv[1], num2 = argv[2];
    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len = len1 + len2;

    result = calloc(len, sizeof(int));
    if (!result)
        errors();

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (b = len2 - 1; b >= 0; b--)
        {
            n2 = num2[b] - '0';
            carry += result[i + b + 1] + (n1 * n2);
            result[i + b + 1] = carry % 10;
            carry /= 10;
        }
        result[i + b + 1] += carry;
    }

    a = 0;
    while (a < len && result[a] == 0)
        a++;
    if (a == len)
        _putchar('0');
    while (a < len)
    {
        _putchar(result[a] + '0');
        a++;
    }
    _putchar('\n');

    free(result);
    return (0);
}
