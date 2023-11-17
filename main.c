#include "main.h"

/**
 * disconnect - Frees memory and exits the program with a specified status.
 * @line: Pointer to the line of text to be freed.
 * @status: Exit status for the program.
 */
void disconnect(char **line, int status)
{
	free(*line);
	_putchar('\n');
	exit(status);
}
/**
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: status
 */

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	int status = 0;

	(void)argc;
	while (1)
	{
		if (isatty(fileno(stdin)) == 1)
		{
			ssize_t len;
			char **arguments;

			printf("$ ");
			len = getline(&lineptr, &n, stdin);
			removenewtag(lineptr, strlen(lineptr));
			arguments = setexecveArgs(lineptr);
			if (len == EOF)
				disconnect(&lineptr, status);
			else if (str_containe(lineptr, "exit") == 0)
			{
				status = arguments[1] ? atoi(arguments[1]) : status;
				free(lineptr);
				exitShell(status, arguments);
			}
			else if (strcmp(lineptr, "env") == 0)
				print_env(environ);
			else
			{
				if (arguments != NULL && arguments[0])
					execute_stdn_cmd(arguments, argv[0], &status);
				else
				{
					freeArguments(arguments);
					continue;
				}
			}
		}
		else
			piped_cmd(lineptr, n, argv[0]);
	}
}
