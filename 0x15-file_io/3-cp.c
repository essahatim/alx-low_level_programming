#include "main.h"

/**
 * main - Function program.
 * @ac: The argument of count.
 * @av: The argument of vector.
 *
 * Return: 1 (success) or 0 (failure)
 */
int main(int ac, char **av)
{
	char buf[1024];
	int from = 0, to = 0;
	ssize_t r, w;

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	from = open(av[1], O_RDONLY);
	to = open(av[2],  O_WRONLY | O_CREAT | O_TRUNC, PERMISSION);
	r = read(from, buf, 1024);
	do
	{
		if (from == -1 || r == -1)
			dprintf(STDERR_FILENO, ER_NORD, av[1]), exit(98);

		w = write(to, buf, r);
		if (to == -1 || w == -1 || w != r)
			dprintf(STDERR_FILENO, ER_NOWR, av[2]), exit(99);
		r = read(from, buf, 1024);
		to = open(av[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	from = close(from);
	to = close(to);
	if (from)
		dprintf(STDERR_FILENO, ER_NOCL, from), exit(100);
	if (to)
		dprintf(STDERR_FILENO, ER_NOCL, from), exit(100);	
	return (1);
}
