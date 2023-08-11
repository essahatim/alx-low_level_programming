#include "main.h"
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Ptr to the file to be created.
 * @text_content: Ptr to the string to add to the end of the file.
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wi;
	int len = 0;

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		len++;
	}
	op = open(filename, O_WRONLY | O_APPEND);
	wi = write(op, text_content, len);
	if (op == -1 || wi == -1)
	return (-1);
	close(op);
	return (1);
}
