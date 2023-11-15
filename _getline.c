#include "main.h"
#include <string.h>
/**
 * _getline - Read a line from a stream.
 * @lineptr: A pointer to the buffer storing the line.
 * @n: A pointer to the size of the buffer.
 * @stream: The input stream to read from.
 * Return: the size of the buffer
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char ch;
	size_t bufsize = 0;
	ssize_t b;
	ssize_t result = 0;
	static size_t buffer_size = 1024;
	char *buffer = malloc(buffer_size + 1);
	char *tmp;

	if (buffer == NULL)
		return (-1);
	while ((b = read(fileno(stream), &ch, 1)) > 0)
	{
		buffer[bufsize++] = ch;
		result++;

		if (bufsize >= buffer_size - 1)
		{
			buffer_size *= 2;
			tmp = realloc(buffer, buffer_size);
			if (tmp == NULL)
			{
				free(buffer);
				return (-1);
			}
			strcpy(buffer, tmp);
		}
		if (ch == '\n')
		{
			buffer[bufsize] = '\0';
			*lineptr = malloc(strlen(buffer) + 1);
			if (*lineptr == NULL)
				return (-1);

			*lineptr = strcpy(*lineptr, buffer);
			*n = strlen(*lineptr);
			return (result);
		}
	}
	free(buffer);
	return (result);
}
