#include "main.h"

/**
 * execute_cmd_no_arguments - Execute a command without any arguments.
 * @lineptr: The command to be executed.
 * @filename: process name
 *
 */

void execute_cmd_no_arguments(char *lineptr, char *filename, char **argv)
{
	pid_t childpid;
	char **cmd;

	if (argv == NULL)
	{
		cmd = malloc(2 * sizeof(char *));
		cmd[0] = lineptr;
		cmd[1] = NULL;
	}
	else
		cmd = setexecveArgs(lineptr);

	childpid = fork();
	if (childpid == -1)
		perror("fork");
	else if (childpid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(filename);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if(isatty(fileno(stdin)) != 1)
		{
			free(cmd);
			exit(0);
		}
	}
	else
		wait(NULL);

	free(cmd);
}

