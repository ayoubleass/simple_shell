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
