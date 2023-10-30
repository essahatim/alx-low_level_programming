#include "main.h"
/**
 * create_file - Appends text at the end of a file.
 * @filename: The file created.
 * @text_content: The text writed.
 *
 * Return: 1 (success) or 0 (failure).
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t fd, w = 0, len = 0;

	if (!filename)
		return (-1);
	if (text_content != NULL)
	{
		for (; text_content[len];)
			len++;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	w = write(fd, text_content, len);
	if (fd == -1 || w == -1)
		return (-1);
	close(fd);
	return (1);
}
