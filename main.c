#include "main.h"

void exitShell(int status, char **argv)
{
	if (argv != NULL)
		freeArguments(argv);
	exit(status);
}

void piped_cmd(char *lineptr, size_t n, char *filename)
{
	ssize_t len;
	char **arguments = malloc(sizeof(char *));
	int status;

	while ((len = getline(&lineptr, &n, stdin)) != -1)
	{
		removenewtag(lineptr, len);
		setexecveArgs(lineptr, arguments);
		execute_stdn_cmd(arguments, filename, &status);
	}
	free(lineptr);
	exit(EXIT_SUCCESS);
}


int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;

	(void)argc;
	while (1)
	{
		if (isatty(fileno(stdin)) == 1)
		{
			int status;
			ssize_t len;
			char **arguments = malloc(sizeof(char *));

			printf("$ ");
			len = getline(&lineptr, &n, stdin);
			removenewtag(lineptr, strlen(lineptr));
			setexecveArgs(lineptr, arguments);
			if (len == EOF)
			{
				free(lineptr);
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			else if (arguments[0] && strcmp(arguments[0], "exit") == 0)
			{
				status = arguments[1] ? atoi(arguments[1]) : 0;
				exitShell(status, arguments);
			}
			else if (strcmp(lineptr, "env") == 0)
			{
				print_env(environ);
			}
			else
			{
				if (arguments[0])
					execute_stdn_cmd(arguments, argv[0], &status);
			}
		}
		else
			piped_cmd(lineptr, n, argv[0]);
	}
}
