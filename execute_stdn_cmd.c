#include "main.h"


/**
 * freeArguments - Frees the memory allocated
 * for an array of strings and the array itself.
 * @argv: The array of strings to be freed.
 *
 * This function iterates through the array of strings pointed to by argv
 * and frees the memory allocated for each string. Finally, it frees the
 * memory allocated for the array itself.
 */
void freeArguments(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}

/**
 * execute_stdn_cmd - Executes a command
 * @lineptr: The command to execute
 * @filename: executable name
 * @status: int
 */
void execute_stdn_cmd(char *lineptr, char *filename, int *status)
{
	static int count;
	char **argv = setexecveArgs(lineptr);
	char *pathcpy = malloc(strlen(getenv("PATH")) + 1);
	pid_t childpid;
	char *cmd;

	strcpy(pathcpy, getenv("PATH"));
	cmd = handleCommand(pathcpy, argv[0]);
	if (cmd == NULL)
	{
		count = 0;
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

