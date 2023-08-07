#include "main.h"
/**
 * create_file - Creates a file.
 * @filename: Ptr to the file to be created.
 * @text_content: Ptr to a string.
 * Return: 1 on success, 0 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wi;
	int len = 0;

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		len++;
	}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wi = write(fd, text_content, len);
	if (fd == -1 || wi == -1)
	return (-1);
	close(fd);
	return (1);
}
