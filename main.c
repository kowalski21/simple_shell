#include "main.h"



/**
 * parse_arguments - parses arguments
 * @command: command
 * Return: array of arguments
*/

char **parse_arguments(char *command)
{
char **args;
args = _strtok(command, " ");
if (!args[0])
perror("No command found");
return (args);
}

/**
 * read_command - reads command
 * Return: command
*/

char *read_command(void)
{
size_t command_size = 0;
ssize_t chars_read;
char *command = NULL;
chars_read = _getline(&command, &command_size, STDIN_FILENO);
if (chars_read == -1)
{
if (isatty(STDIN_FILENO))
exit(0);
}
command[chars_read - 1] = '\0';
return (command);
}

/**
 * execute_builtin_commands - executes builtin commands
 * @args: array of arguments
 * @cmd: command
 * Return: 1 if builtin command is executed, 0 if not
*/
int execute_builtin_commands(char **args, char *cmd)
{
int num_args = count_items_in_char_array(args);
if (stringCompare(args[0], "exit") == 0)
{
if (num_args == 2)
{
free(cmd);
exit(_atoi(args[1]));
}
exit(0);
}

if (stringCompare(args[0], "env") == 0)
{
print_env(environ);
return (1);
}
return (0);
}



/**
 * process_command - processes command
 * @args: array of arguments
 * @path: path
 * Return: void
*/

void process_command(char **args, char *path)
{
int status;
char *foundPath = checkCommand(path, args[0]);
if (foundPath != NULL)
args[0] = foundPath;
else
{
if (isValidFilePath(args[0]))
foundPath = args[0];
else
{
show_error();
return;
}
}
exec_command(args, &status);
}

/**
 * main - main function
 * Return: 0 on success, 1 on failure
*/

int main(void)
{
char **args;
char *command, *path = _getenv("PATH");
signal(SIGINT, sig_handler);
while (1)
{
print_prompt();
command = read_command();
if (stringLength(command) == 0)
continue;
args = parse_arguments(command);
if (execute_builtin_commands(args, command))
continue;
process_command(args, path);
free(command);
}
return (0);
}
