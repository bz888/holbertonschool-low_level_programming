/**
 * swap_int - swaps values of int a and b.
 * @a: pointer to an int.
 * @b: pointer to an int.
 */

void swap_int(int *a, int *b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

