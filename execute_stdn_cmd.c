#include "main.h"

 
/**
 * execute_stdn_cmd - Executes a command
 * @lineptr: The command to execute
 * @filename: executable name
 * @status: int
 */
void execute_stdn_cmd(char **argv, char *filename, int *status)
{
	static int count;
	char *pathcpy = malloc(strlen(getenv("PATH")) + 1);
	pid_t childpid;
	char *cmd;

	strcpy(pathcpy, getenv("PATH"));
	cmd = handleCommand(pathcpy, argv[0]);
	if (cmd == NULL)
	{
		count = 0;
		count++;
		printf("%s: %d: %s: not found\n", filename, count, argv[0]);
		free(pathcpy);
		freeArguments(argv);
		free(cmd);
	}
	else
	{
		childpid = fork();
		if (childpid == -1)
		{
			perror("fork");
			free(pathcpy);
			freeArguments(argv);
			free(cmd);
			return;
		}
		if (childpid == 0)
			execve(cmd, argv, environ);
		else
		{
			waitpid(childpid, status, 0);
			freeArguments(argv);
			free(cmd);
			free(pathcpy);
			return;
		}
	}
}

