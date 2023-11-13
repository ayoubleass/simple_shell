#include "main.h"

/**
 * setexecveArgs - Tokenizes a string into an array of arguments for execve
 * @lineptr: The input string to tokenize
 * Return: A dynamically allocated array of strings (arguments), or NULL on
 * failure
 */
char **setexecveArgs(char *lineptr)
{
	char *token;
	int i = 0;
	char **argv = malloc(sizeof(char *));

	if (lineptr == NULL)
		return (NULL);

	token = strtok(lineptr, " \t\n");

	while (token != NULL)
	{
		argv = realloc(argv, (i + 2) * sizeof(char *));
		if (argv == NULL)
			return NULL;

		argv[i] = malloc(strlen(token) + 1);
		if (argv[i] == NULL)
			return (NULL);

		strcpy(argv[i], token);
		token = strtok(NULL, " \t\n");
		i++;
	}

	argv[i] = NULL;
	return (argv);
}

/*
char **setexecveArgs(char *lineptr)
{
	char *token;
	int i = 0;
	char **argv = malloc(sizeof(char *));

	if (lineptr == NULL)
		return (NULL);
	token = strtok(lineptr, " \t\n");

	while (token != NULL)
	{
		argv[i] = malloc(strlen(token) + 1);
		if (argv[i] == NULL)
			return (NULL);
		strcpy(argv[i], token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
*/

/**
 * print_env - Prints each environment variable separately
 *
 * @env: The array of environment variables
 */
void print_env(char **env)
{
	int i = 0;
	int j;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			_putchar(env[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}


/**
 * removenewtag - Removes the newline character from the end of a string.
 *
 * @lineptr: The string to process.
 * @linelen: The length of the string.
 */
void removenewtag(char *lineptr, ssize_t linelen)
{
	if (linelen > 0 && lineptr[linelen - 1] == '\n')
	{
		lineptr[linelen - 1] = '\0';
		linelen--;
	}
}
