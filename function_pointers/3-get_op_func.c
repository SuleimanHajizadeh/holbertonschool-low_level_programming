#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function for a given operator
 * @s: operator as a string ("+", "-", "*", "/", "%")
 *
 * Return: pointer to the corresponding function, or NULL if not found
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && strcmp(s, ops[i].op) != 0)
		i++;
	return (ops[i].f);
}
