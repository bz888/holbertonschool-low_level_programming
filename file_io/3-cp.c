#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * main - copies the content of a file to another file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd1, fd2;
	ssize_t r, w, t;
	char b[1024];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	fd2 = open(av[2], O_WRONLY | O_CREAT | O_EXCL, 0664);
	if (fd2 != -1 && fchmod(fd2, 0664) == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	if (fd2 == -1)
		fd2 = open(av[2], O_WRONLY | O_TRUNC);
	if (fd2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	while ((r = read(fd1, b, 1024)) > 0)
	{
		for (t = 0; t < r; t += w)
		{
			w = write(fd2, b + t, r - t);
			if (w == -1)
				dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", av[2]), exit(99);
		}
	}
	if (r == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	if (close(fd1) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1), exit(100);
	if (close(fd2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2), exit(100);
	return (0);
}

