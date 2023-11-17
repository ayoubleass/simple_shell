#include "main.h"
/**
 * execute_stdn_cmd - Execute a command with arguments.
 * @argv: A pointer to an array of strings representing
 * the command and its arguments.
 * @filename: The name of the program invoking the function.
 * @status: A pointer to an integer where
 * the status of the executed command will be stored.
 */
void  execute_stdn_cmd(char **argv, char *filename, int *status)
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
		*status = 127;
	}
	else
	{
		childpid = fork();
		if (childpid == -1)
			perror("fork");
		else if (childpid == 0)
		{
			if (execve(cmd, argv, environ) == 0)
				status = 0;
		}
		else
			waitpid(childpid, status, 0);
	}
	free(cmd);
	freeArguments(argv);
	free(pathcpy);
}

