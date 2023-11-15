#include "main.h"

/**
 * exitShell - Exits the shell with the specified status.
 * @status: The exit status.
 * @argv: A pointer to an array of strings representing arguments.
 */
void exitShell(int status, char **argv)
{
	if (argv != NULL)
		freeArguments(argv);
	exit(status);
}

/**
 * piped_cmd - Reads input from stdin, processes, and executes commands.
 * @lineptr: A pointer to the input string.
 * @n: The size of the input buffer.
 * @filename: The name of the program invoking the function.
 */
void piped_cmd(char *lineptr, size_t n, char *filename)
{
	ssize_t len;
	char **arguments;
	int status;

	while ((len = getline(&lineptr, &n, stdin)) != -1)
	{
		removenewtag(lineptr, len);
		arguments = setexecveArgs(lineptr);
		execute_stdn_cmd(arguments, filename, &status);
	}
	free(lineptr);
	exit(EXIT_SUCCESS);
}

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
		if (isatty(fileno(stdin)) == 1)
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
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			else
			{
				execute_cmd_no_arguments(lineptr, argv[0]);
			}
		}
		else
			piped_cmd(lineptr, n, argv[0]);
	}
}
