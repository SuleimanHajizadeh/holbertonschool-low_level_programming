#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* _putchar implementation */
int _putchar(char c)
{
    return putchar(c);
}

/* Check if a string contains only digits */
int is_number(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

/* Multiply two strings representing numbers */
char *multiply_strings(const char *num1, const char *num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int totalLen = len1 + len2;
    int *res = calloc(totalLen, sizeof(int));
    char *result_str;
    int i, j, carry, sum, pos = 0;

    if (!res)
        return NULL;

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            sum = (num1[i]-'0') * (num2[j]-'0') + res[i+j+1] + carry;
            res[i+j+1] = sum % 10;
            carry = sum / 10;
        }
        res[i+j+1] += carry;
    }

    /* Skip leading zeros */
    i = 0;
    while (i < totalLen && res[i] == 0)
        i++;

    if (i == totalLen)  /* result is 0 */
    {
        result_str = malloc(2);
        if (!result_str) { free(res); return NULL; }
        result_str[0] = '0';
        result_str[1] = '\0';
        free(res);
        return result_str;
    }

    result_str = malloc(totalLen - i + 1);
    if (!result_str) { free(res); return NULL; }

    for (; i < totalLen; i++)
        result_str[pos++] = res[i] + '0';
    result_str[pos] = '\0';

    free(res);
    return result_str;
}

int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    if (!is_number(argv[1]) || !is_number(argv[2]))
    {
        printf("Error\n");
        return 98;
    }

    result = multiply_strings(argv[1], argv[2]);
    if (!result)
        return 98;

    for (int i = 0; result[i]; i++)
        _putchar(result[i]);
    _putchar('\n');

    free(result);
    return 0;
}
