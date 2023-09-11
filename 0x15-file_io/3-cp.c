#include "main.h"

/**
 * main - Copies the contents of a file to another file.
 * @ac: The num of arguments.
 * @av: An array of pointers to the arguments.
 * Return: 1 (success), 0 (failure).
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int ac, char **av)
{
	int from = 0, to = 0;
	ssize_t r;
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (ac != 3)
		dprintf(STDERR_FILENO, "USAGE : cp file_from file_to\n");
		exit(97);

	from = open(av[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	while ((r = read(from, buf, 1024)) > 0)
		if (write(to, buf, r) != r)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
	if (r == 1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);

	from = close(from)
	to = close(to)
	if (from)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	if (to)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	return (1);
}
