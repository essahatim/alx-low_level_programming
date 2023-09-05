#include "main.h"
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file to create.
 * @text_content: The text to write to the file.
 * Return: 1 (success), 0 (failure).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;
	ssize_t w = 0;

	if (!filename)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (len)
		w = write(fd, text_content, len);
	close(fd);
	return (w == len ? 1 : -1);
}
