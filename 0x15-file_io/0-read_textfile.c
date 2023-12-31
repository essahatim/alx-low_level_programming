#include"main.h"

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The file readed.
 * @letters: The bytes reded.
 *
 * Return: The number of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, w, r;
	char buf[1024 * 8];

	if (!filename || !letters)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, &buf[0], letters);
	w = write(STDOUT_FILENO, &buf[0], r);
	close(fd);
	return (w);
}
