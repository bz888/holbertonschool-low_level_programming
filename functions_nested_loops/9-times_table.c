#include "main.h"

/**
 * times_table - does things
 *
 */
void times_table(void)
{
	int x, y, v;

	for (x = 0; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			v = x * y;
			if (y == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				if (v < 10)
				{
					_putchar(' ');
					_putchar('0' + v);
				}
				else
				{
					_putchar('0' + (v / 10));
					_putchar('0' + (v % 10));
				}
			}
		}
		_putchar('\n');

	}
}

