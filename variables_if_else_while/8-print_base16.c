#include <stdio.h>

/**
 * main - Prints
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char *hex;

	hex = "0123456789abcdef";

	for (i = 0; i < 16; i++)
		putchar(hex[i]);

	putchar('\n');

	return (0);
}
