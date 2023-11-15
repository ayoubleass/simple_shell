#include "main.h"

/**
 * execute_cmd_no_arguments - Execute a command without any arguments.
 * @lineptr: The command to be executed.
 * @filename: process name
 */

void execute_cmd_no_arguments(char *lineptr, char *filename)
{
	pid_t childpid;
	char *cmd[] = {lineptr, NULL};

	childpid = fork();
	if (childpid == -1)
		perror("fork");
	else if (childpid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			perror(filename);
	}
	else
	wait(NULL);
}

