#include "main.h"
/**
 * Description:
 * If the argument count is incorrect - exit code 97.
 * If file_from_fd does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from_fd cannot be closed - exit code 100.
 */
/**
 * create_buf - Allocates 1024 bytes for a buf.
 * @file: The name of the file buf is storing chars for.
 * Return: The newly-allocated buff.
 */
char *create_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}
/**
 * main - Copies the contents of a file to another file.
 * @ac: The num of arguments.
 * @av: An array of pointers to the arguments.
 * Return: 0 (success).
 */
int main(int ac, char *av[])
{
	int from_fd, to_fd;
	ssize_t r, w;
	char *buf;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buf(av[2]);
	from_fd = open(av[1], O_RDONLY);
	r = read(from_fd, buf, 1024);
	to_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from_fd == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from_fd file %s\n", av[1]);
			free(buf);
			exit(98);
		}
		w = write(to_fd, buf, r);
		if (to_fd == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to_fd %s\n", av[2]);
			free(buf);
			exit(99);
		}
		r = read(from_fd, buffer, 1024);
		to_fd = open(av[2], O_WRONLY | O_APPEND);
	} while (r > 0);
/**
 * close_file - Closes file.
 * @fd: The file to be closed.
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);
	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
	free(buf);
	close_file(from_fd);
	close_file(to_fd);
	return (0);
}
