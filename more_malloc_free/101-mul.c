#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Exit with "Error\n" and status 98 */
static void print_error(void)
{
    printf("Error\n");
    exit(98);
}

/* Return 1 if s is non-empty and composed only of decimal digits */
static int is_digit_str(const char *s)
{
    if (!s || *s == '\0')
        return 0;
    for (; *s; s++)
        if (!isdigit((unsigned char)*s))
            return 0;
    return 1;
}

/* Multiply two non-negative integer strings and print the result */
static void multiply_and_print(const char *num1, const char *num2)
{
    size_t len1 = strlen(num1), len2 = strlen(num2);
    size_t len = len1 + len2;
    int *res = calloc(len, sizeof(int));
    size_t i, j;

    if (!res)
        print_error();

    /* Grade-school multiplication */
    for (i = 0; i < len1; i++)
    {
        int d1 = num1[len1 - 1 - i] - '0';
        int carry = 0;

        for (j = 0; j < len2; j++)
        {
            int d2 = num2[len2 - 1 - j] - '0';
            int sum = d1 * d2 + res[len - 1 - (i + j)] + carry;

            res[len - 1 - (i + j)] = sum % 10;
            carry = sum / 10;
        }
        res[len - 1 - (i + j)] += carry;
    }

    /* Skip leading zeros */
    i = 0;
    while (i < len - 1 && res[i] == 0)
        i++;

    /* Print result */
    for (; i < len; i++)
        putchar(res[i] + '0');
    putchar('\n');

    free(res);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        print_error();

    if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
        print_error();

    /* Handle simple zero cases early */
    if ((argv[1][0] == '0' && argv[1][1] == '\0') ||
        (argv[2][0] == '0' && argv[2][1] == '\0'))
    {
        puts("0");
        return 0;
    }

    multiply_and_print(argv[1], argv[2]);
    return 0;
}