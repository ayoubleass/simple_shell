#include "main.h"

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;

	while (1)
	{
		int status;
		ssize_t len;

		if (isatty(fileno(stdin)) == 1)
		{
			printf("$ ");
			len = getline(&lineptr, &n, stdin);
			if (len == EOF)
			{
				free(lineptr);
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			removenewtag(lineptr, strlen(lineptr));
			if (strcmp(lineptr, "exit") == 0)
			{
				free(lineptr);
				exit(EXIT_SUCCESS);
			}

			execute_stdn_cmd(lineptr, argv[0], &status);
		}
		else
		{
			while ((len = getline(&lineptr, &n, stdin)) != -1)
			{
				removenewtag(lineptr, len);
				execute_stdn_cmd(lineptr, argv[argc - argc], &status);
			}
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
	}
}
