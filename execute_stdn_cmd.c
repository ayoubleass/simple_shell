#include "main.h"


void freeArguments(char **argv)
{
	int i;

	for(i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}


void execute_stdn_cmd(char *lineptr, char *filename, int *status)
{
	static int count = 0;
	char **argv = setexecveArgs(lineptr);
	char *pathcpy = malloc(strlen(getenv("PATH")) + 1);
	pid_t childpid;
	char *cmd;

	strcpy(pathcpy, getenv("PATH"));
	cmd = handleCommand(pathcpy, argv[0]);
	if (cmd == NULL)
	{
		count++;
		printf("%s: %d: %s: not found\n", filename, count, lineptr);
		free(pathcpy);
		freeArguments(argv);
		free(cmd);
	}
	else
	{
		childpid = fork();
		if (childpid == -1)
			perror("fork");

		if (childpid == 0)
			execve(cmd, argv, environ);
		else 
		{
			waitpid(childpid, status, 0);
			freeArguments(argv);
			free(cmd);
			free(pathcpy);
		}
	}
}

