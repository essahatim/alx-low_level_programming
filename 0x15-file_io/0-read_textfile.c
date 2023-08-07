#include<stdlib.h>
#include"main.h"

/**
 * read_textfile- Reads a text file and prints it to the POSIX standard output.
 * @filename: The text  file   reading.
 * @letters: The num of letters it should read and print.
 * Return: 0  can not be opened or read ,filename is NULL,
 * write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

	int fd;
	char *buf;
	ssize_t wi;
	ssize_t ti;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);
	buf = malloc(sizeof(char) * letters);
	ti = read(fd, buf, letters);
	wi = write(STDOUT_FILENO, buf, ti);
	free(buf);
	close(fd);
	return (wi);
}
