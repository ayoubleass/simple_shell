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

		printf("#cisfun$ ");
		len = getline(&lineptr, &n, stdin);
		removenewtag(lineptr, strlen(lineptr));
		/*arguments = setexecveArgs(lineptr);*/
		if (len == EOF)
		{
			free(lineptr);
			if (isatty(fileno(stdin)) == 1)
				_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else
		{
			if(lineptr != NULL && lineptr[0] != '\0')
				execute_cmd_no_arguments(lineptr, argv[0]);
		}
	}
}
