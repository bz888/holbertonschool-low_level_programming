/**
 * lookup_sqrt - searches for natural sqrt using binary search
 * @n: number
 * @low: lower bound (must be >= 1)
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

	if (n / mid == mid && n % mid == 0)
		return (mid);
	if (n / mid < mid)
		return (lookup_sqrt(n, low, mid - 1));

	return (lookup_sqrt(n, mid + 1, high));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to evaluate
 *
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (lookup_sqrt(n, 1, n));
}

