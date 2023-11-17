#include "main.h"

/**
 * execute_cmd_no_arguments - Execute a command without any arguments.
 * @lineptr: The command to be executed.
 * @filename: process name
 * @argv: command arguments
 */

void execute_cmd_no_arguments(char *lineptr, char *filename, char **argv)
{
	pid_t childpid;
	char **cmd = NULL;

	if (argv == NULL)
	{
		cmd = malloc(2 * sizeof(char *));
		cmd[0] = _remove(lineptr, " ");
		cmd[1] = NULL;
	}

	childpid = fork();
	if (childpid == -1)
		perror("fork");
	else if (childpid == 0)
	{
		if (!execve((cmd != NULL) ? cmd[0]
			: argv[0], (cmd != NULL) ? cmd : argv, environ))
		{
			perror(filename);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);

	free(cmd);
	if (argv != NULL)
		freeArguments(argv);
}

