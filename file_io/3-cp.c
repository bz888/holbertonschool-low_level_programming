#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * print_usage - prints usage error and exits
 */
void print_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * print_read_error - prints read error and exits
 * @filename: source file name
 */
void print_read_error(char *filename)
{
	dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * print_write_error - prints write error and exits
 * @filename: destination file name
 */
void print_write_error(char *filename)
{
	dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies content from one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w, total;
	char buffer[1024];

	if (argc != 3)
		print_usage();

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_read_error(argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0664);
	if (fd_to != -1)
	{
		if (fchmod(fd_to, 0664) == -1)
			print_write_error(argv[2]);
	}
	else
	{
		fd_to = open(argv[2], O_WRONLY | O_TRUNC);
		if (fd_to == -1)
			print_write_error(argv[2]);
	}

	r = read(fd_from, buffer, 1024);
	while (r > 0)
	{
		total = 0;
		while (total < r)
		{
			w = write(fd_to, buffer + total, r - total);
			if (w == -1)
				print_write_error(argv[2]);
			total += w;
		}
		r = read(fd_from, buffer, 1024);
	}

	if (r == -1)
		print_read_error(argv[1]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

