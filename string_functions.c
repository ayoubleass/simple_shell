#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @s: The input string
 * Return: The length of the string 's'
 */

int _strlen(const char *s)
{
	if (*s != '\0')
		return (1 + _strlen(s + 1));
	return (0);
}
/**
 * _strcat - Concatenates two strings
 * @s: The first string
 * @str: The second string to be concatenated
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *s, char *str)
{
	int len1, len2, i, j;
	char *newVersion;

	len1 = _strlen(s);
	len2 = _strlen(str);

	newVersion = malloc(len1 + len2 + 1);
	if (newVersion == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		newVersion[i] = s[i];
	}

	for (j = 0; j < len2; j++)
	{
		newVersion[len1 + j] = str[j];
	}

	newVersion[len1 + len2] = '\0';
	return (newVersion);
}
/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination string
 * @src: The source string to be copied
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: An integer less than, equal to, or greater than zero
 *         if s1 is found to be less than, equal to, or greater than s2
 */

int _strcmp(char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * str_containe - Checks if the beginning of a string matches another string
 * @s: The string to check
 * @str: The substring to compare with the beginning of 's'
 * Return: 0 if 'str' is found at the beginning of 's', -1 otherwise
 */

int str_containe(char *s, char *str)
{
	int i = 0;

	while (i < _strlen(str))
	{
		if (str[i] != s[i])
			return (-1);
		i++;
	}
	return (0);
}
