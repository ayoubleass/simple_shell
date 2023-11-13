#include "main.h"

char *_remove(char *str, char *delim)
{
	size_t len = strlen(delim);

	while (strncmp(str, delim, len) == 0)
	{
		str += len;
	}
	return (str);
}


char *buildCmd(char *path, char *lineptr)
{
	char *token = strtok(path, ":");
	struct stat st;
	char *cmd = NULL;
	char * result = NULL;

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
	return result;

}


char *handleCommand(char *path, char *lineptr)
{
	if (lineptr == NULL)
		return NULL;
	if (str_containe(lineptr, "/bin") == 0)
		return buildCmd(path, _remove(lineptr, "/bin/"));
	else
		return buildCmd(path, lineptr);
	return (NULL);
}
