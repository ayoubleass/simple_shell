#include "main.h"

/**
 * execute_cmd_no_arguments - Execute a command without any arguments.
 * @lineptr: The command to be executed.
 * @filename: process name
 *
 */

void execute_cmd_no_arguments(char *lineptr, char *filename)
{
	pid_t childpid;
	char **cmd = malloc(2 * sizeof(char *));

	cmd[0] = lineptr;
	cmd[1] = NULL;

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
	}
	else
		wait(NULL);

	free(cmd);
}

