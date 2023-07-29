#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

extern char **environ;
char *stringBytesConcat(char *dest, char *src, size_t num);
char *stringConcat(char *destination, char *source);
int stringLength(const char *str);
char *stringSearch(char *str, char c);
char *searchSubString(char *haystack, char *needle);
int stringCompare(char *s1, char *s2);
char *_strpbrk(char *s, char *accept);
char **_strtok(char *line, char *delim);
int tokenLength(char *delimeter, char *str);
int tokenCounter(char *delimeter, char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
void print_prompt(void);
void sig_handler(int sig);

void freeTokens(char **tokens);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void reassign_ptr(char *buffer, size_t *n, char **ptr, size_t fixer);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t _strcspn(char *str1, char *str2);
char *_strdup(char *str);
void _printf(char *str);
void print_env(char **env_var);
int _atoi(char *s);
char *checkCommand(char *path, char *cmd);


void exec_command(char **args, int *status);

void show_error(void);
char *findCommandPath(char *cmd, char **pathArray, int numPaths);
int isValidFilePath(char *filePath);
void freeArgsArray(char **array, int size);


void free_environ(void);
char *_getenv(char *name);


void print_contents(char **arr);
size_t count_items_in_char_array(char **arr);
char **findPath(char *path);
#endif
