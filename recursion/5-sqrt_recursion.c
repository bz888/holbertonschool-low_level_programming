/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to evaluate
 *
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	static int i = 1;

	if (n < 0)
		return (-1);

	if (i * i == n)
	{
		i = 1;
		return (i * i == n ? i : i); /* return i */
	}

	if (i * i > n)
	{
		i = 1;
		return (-1);
	}

	i++;
	return (_sqrt_recursion(n));
}

