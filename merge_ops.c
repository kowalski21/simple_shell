#include "main.h"

/**
 * exec_command - executes a command
 * @args: array of arguments
 * @status: exit status
 * Return: 0 on success, 1 on failure
 */

void exec_command(char **args, int *status)
{
pid_t pid;
pid = fork();
if (pid < 0)
perror("Fork error");
else if (pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
_printf(args[0]);
_printf(": command not found\n");
exit(EXIT_FAILURE);
}
}
else
waitpid(pid, status, 0);
}

/**
 * checkCommand - checks if a command is valid
 * @path: path
 * @cmd: command
 * Return: path of command if found, NULL if not found
*/

char *checkCommand(char *path, char *cmd)
{
char **pathArray, *foundPath = NULL;
int num_args = 0;
int i;
pathArray = findPath(path);
num_args = count_items_in_char_array(pathArray);
foundPath = findCommandPath(cmd, pathArray, num_args);
for (i = 0; i < num_args; i++)
free(pathArray[i]);
free(pathArray);

return (foundPath);
}


/**
 * print_prompt - prints prompt
 * Return: void
*/
void print_prompt(void)
{
if (isatty(STDIN_FILENO))
write(1, "$ ", 2);
}
