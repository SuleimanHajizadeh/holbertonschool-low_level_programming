#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - helper function to check palindrome
 * @s: string
 * @left: left index
 * @right: right index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int left, int right)
{
	if (left >= right)
		return (1);
	if (s[left] != s[right])
		return (0);
	return (check_palindrome(s, left + 1, right - 1));
}

/**
 * is_palindrome - checks if string is a palindrome
 * @s: string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	if (len == 0)
		return (1);
	return (check_palindrome(s, 0, len - 1));
}
