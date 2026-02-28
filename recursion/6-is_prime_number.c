/**
 * prime_helper - checks divisibility
 * @n: number to test
 * @i: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - checks if n is prime
 * @n: number to evaluate
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (prime_helper(n, 2));
}

