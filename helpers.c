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
	int i = 0;

	if (argv == NULL)
		return;
	while (argv[i] != NULL)
	{
		if (argv[i] && argv[i] != NULL)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
		i++;
	}

	free(argv);
}

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
	char **argv;

	if (lineptr == NULL || lineptr[0] == '\0')
		return (NULL);

	argv = malloc(sizeof(char *) * INITIAL_SIZE);
	if (argv == NULL)
		return (NULL);

	while ((token = strtok(lineptr, " \t\n")) != NULL)
	{
		if (i >= INITIAL_SIZE)
		{
			char **temp = realloc(argv, sizeof(char *) * (i + 1));

			if (temp == NULL)
			{
				freeArguments(argv);
				return (NULL);
			}
			argv = temp;
		}
		argv[i] = malloc(strlen(token) + 1);
		if (argv[i] == NULL)
		{
			freeArguments(argv);
			return (NULL);
		}
		strcpy(argv[i], token);
		lineptr = NULL;
		i++;
	}

	argv[i] = NULL;
	return (argv);
}
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
	if (linelen == 0)
		return;
	if (linelen > 0 && lineptr[linelen - 1] == '\n')
	{
		lineptr[linelen - 1] = '\0';
		linelen--;
	}
}
