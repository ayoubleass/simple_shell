#include "main.h"

/**
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: status
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;

	(void)argc;
	while (1)
	{
		ssize_t len;
		if (isatty(fileno(stdin)) == 1)
			printf("$ ");
		len = getline(&lineptr, &n, stdin);
		lineptr[len - 1] = '\0';
		if (len == EOF)
		{
			free(lineptr);
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else
		{
			execute_cmd_no_arguments(lineptr, argv[0], NULL);
			if (isatty(fileno(stdin)) != 1)
			{
				free(lineptr);
				exit(EXIT_SUCCESS);
			}
		}
	}
	return (0);
}
