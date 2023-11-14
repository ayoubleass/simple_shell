#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


extern char **environ;

ssize_t _putchar(char c);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int _strcmp(char *s1, const char *s2);
int _strlen(const char *s);
char *_strcat(char *s, char *str);
char *_strcpy(char *dest, char *src);
int str_containe(char *s, char *str);

char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *handleCommand(char *path_copy, char *lineptr);

void setexecveArgs(char *lineptr,char **argv);
void execute_cmd_with_no_arg(char *lineptr,char *filename);
void removenewtag(char *lineptr, ssize_t linelen);
void execute_stdn_cmd(char **argv, char *filename, int *status);
void print_env(char **env);
void freeArguments(char **argv);


#endif
