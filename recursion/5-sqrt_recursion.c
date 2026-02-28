/**
 * lookup_sqrt - searches for natural sqrt using binary search
 * @n: number
 * @low: lower bound
 * @high: upper bound
 *
 * Return: natural sqrt or -1
 */
int lookup_sqrt(int n, int low, int high)
{
	int mid;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	if (mid == 0)
		return (-1);

	if (n / mid == mid && n % mid == 0)
		return (mid);
	else if (n / mid < mid)
		return (lookup_sqrt(n, low, mid - 1));
	else
		return (lookup_sqrt(n, mid + 1, high));
}

/**
 * _sqrt_recursion - returns natural square root
 * @n: number to evaluate
 *
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (lookup_sqrt(n, 0, n));
}

