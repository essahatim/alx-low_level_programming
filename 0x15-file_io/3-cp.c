#include "main.h"
/**
 * close_file - Closes the file.
 * @fd: the file to be closed.
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);
	if (cl == -1)
		dprintf(STDERR_FILENO, ER_NOCL, fd), exit(100);
}
/**
 * main - Function program.
 * @ac: The argument of count.
 * @av: The argument of vector.
 *
 * Return: 1 (success) or 0 (failure).
 */
int main(int ac, char **av)
{
	char buf[1024];
	int from, to;
	ssize_t w, r;

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	from = open(av[1], O_RDONLY);
	r = read(from, buf, 1024);
	while (r > 0)
	if (from == -1)
		dprintf(STDERR_FILENO, ER_NORD, av[1]), exit(98);
	to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
		dprintf(STDERR_FILENO, ER_NOWR, av[2]), exit(99);
	w = write(to, buf, r);
		if (w != r)
			dprintf(STDERR_FILENO, ER_NOWR, av[2]), exit(99);
	if (r == -1)
		dprintf(STDERR_FILENO, ER_NORD, av[1]), exit(98);
	close_file(from);
	close_file(to);
	return (EXIT_SUCCESS);
}
