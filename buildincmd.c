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
 * checkisBuildin - Checks if a given
 * command is a built-in command in a simple shell.
 * @cmd: The command to be checked.
 * Return: 1 if there is a match or 0 if not
 */
int checkisBuildin(char *cmd)
{
	char buildin[][5] = {"exit", "env"};
	size_t i;

	for (i = 0; i < sizeof(buildin) / sizeof(buildin[0]); ++i)
	{
		if (strcmp(buildin[i], cmd) == 0)
			return (1);
	}

	return (0);
}


/**
 * handleBuildinCmd - Executes built-in commands based on the given command.
 * @cmd: The command to be handled.
 * @status: The exit status of the previous command.
 * @args: Array of arguments (if any) associated with the command.
 */

void handleBuildinCmd(char *cmd, int status, char **args)
{
	if (strcmp(cmd, "env") == 0)
		print_env(environ);
	else if (strcmp(cmd, "exit") == 0)
	{
		freeArguments(args);
		exit(status);

	}
}



