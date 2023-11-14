#include "main.h"

/**
 * _putchar - Writes a single character to the standard output.
 * @c: The character to be written.
 * Return: On success, the number of bytes written (1);
 * on error, -1 is returned.
 */
ssize_t _putchar(char c)
{
	return (write(1, &c, 1));
}
