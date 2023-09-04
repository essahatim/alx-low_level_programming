#include "main.h"
/**
 * read_textfile- Reads a text file and prints it to the POSIX standard output.
 * @filename: Name of file being read.
 * @letters: Num of bytes to be reading.
 * Return: Num of bytes read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes, w;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	bytes = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, bytes);
	free(buf);
	close(fd);
	return (w);
}
