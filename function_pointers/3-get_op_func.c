#include "3-calc.h"

/**
 * get_op_func - select fucntion to perform operation
 * @s: operator
 *
 * Return: a pointer to a function
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
	int i = 0;

	if (!s)
		return (NULL);

	while (ops[i].op && ops[i].f && strcmp(s, ops[i].op))
		i++;

	return (ops[i].f);
}

