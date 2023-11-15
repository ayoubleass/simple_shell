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
		/*int status;*/
		ssize_t len;
		/*char **arguments;*/
		if (isatty(fileno(stdin)) == 1)
			printf("#cisfun$ ");
		len = getline(&lineptr, &n, stdin);
		lineptr[len - 1] = '\0';
		/*arguments = setexecveArgs(lineptr);*/
		if (len == EOF)
		{
			free(lineptr);
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (lineptr != NULL && lineptr[0] != '\0')
			{
				execute_cmd_no_arguments(lineptr, argv[0], NULL);
				if (isatty(fileno(stdin)) != 1)
				{
					free(lineptr);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}
