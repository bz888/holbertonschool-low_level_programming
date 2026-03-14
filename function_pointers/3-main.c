#include "3-calc.h"

/**
 * main - applies calculator operations
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0 if no error, terminate program otherwise
 */
int main(int argc, char *argv[])
{
	int (*calculate)(int, int), operand_1, operand_2;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	operand_1 = atoi(argv[1]);
	operand_2 = atoi(argv[3]);
	calculate = get_op_func(argv[2]);

	if (!calculate)
	{
		printf("Error\n");
		exit(99);
	}

	if (!operand_2 && !(strcmp(argv[2], "%") && strcmp(argv[2], "/")))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", calculate(operand_1, operand_2));
	return (0);
}

