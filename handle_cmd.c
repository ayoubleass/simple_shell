#include "main.h"

/**
 * _remove - Removes a specified prefix from a string.
 * @str: The input string from which the prefix is to be removed.
 * @delim: The prefix to be removed from the beginning of the string.
 *
 * Return: A pointer to the modified string after removing the prefix.
 */
char *_remove(char *str, char *delim)
{
	size_t len = strlen(delim);

	while (strncmp(str, delim, len) == 0)
	{
		str += len;
	}
	return (str);
}


/**
 * buildCmd - Builds a command path by concatenating
 * a given directory path and a filename.
 * @path: The directory path containing ':'-separated directories.
 * @lineptr: The filename to be appended to the directory path.
 *
 * Return: A dynamically allocated string representing the valid command path,
 *         or NULL if no valid path is found.
 */


char *buildCmd(char *path, char *lineptr)
{
	char *token = strtok(path, ":");
	struct stat st;
	char *cmd = NULL, *result = NULL;

	while (token != NULL)
	{
		cmd = malloc(strlen(token) + strlen("/") + strlen(lineptr) + 1);
		if (cmd == NULL)
			return (NULL);
		strcpy(cmd, token);
		cmd = strcat(cmd, "/");
		cmd = strcat(cmd, lineptr);
		if (stat(cmd, &st) == 0)
		{
			result = (cmd);
			break;
		}
		else
		{
			free(cmd);
		}
		token = strtok(NULL, ":");
	};
	return (result);

}

/**
 * handleCommand - Handles the command by preparing
 * the appropriate command path.
 * @path: The directory path containing ':'-separated directories.
 * @lineptr: The command to be handled, which may include a '/bin/' prefix.
 * Return: A dynamically allocated string representing the valid command path,
 *         or NULL if the input command is NULL or if memory allocation fails.
 */
char *handleCommand(char *path, char *lineptr)
{
	if (lineptr == NULL)
		return (NULL);
	if (str_containe(lineptr, "/bin") == 0)
		return (buildCmd(path, _remove(lineptr, "/bin/")));
	else
		return (buildCmd(path, lineptr));
	return (NULL);
}
