#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * create_buffer - A buffer  for allocates 1024 bytes  .
 * @file: The file buffer is storing chars for.
 * Return: A ptr to  buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
	}
	return (buffer);
}

/*
 * close_file - Closes the file descriptor.
 * @fd: A file descriptor.
 */
void close_file(int fd)
{
	int Cl;

	Cl = close(fd);
	if (Cl == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @ac: Arguments count.
 * @av: Argument vector.
 * Return: 1 on success, 0 on failure.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int ac, char *av[])
{
	int from_fd, to_fd;
	int re, wi;
	char *buffer;

	if (ac != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}
	buffer = create_buffer(av[2]);
	from_fd = open(av[1], O_RDONLY);
	re = read(from_fd, buffer, 1024);
	to_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from_fd == -1 || re == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't read from_fd file %s\n", av[1]);
		free(buffer);
		exit(98);
		}
		wi = write(to_fd, buffer, re);
		if (to_fd == -1 || wi == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't write to_fd %s\n", av[2]);
		free(buffer);
		exit(99);
		}
		re = read(from_fd, buffer, 1024);
		to_fd = open(av[2], O_WRONLY | O_APPEND);
	}
	while (re > 0)
	free(buffer);
	close_file(from_fd);
	close_file(to_fd);
	return (0);
}
