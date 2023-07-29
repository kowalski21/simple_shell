
#include "main.h"
/**
 * findPath - Finds the path of the given command.
 * @path: The path to be searched.
 * Return: The path of the command if found, NULL otherwise.
 *
*/
char **findPath(char *path)
{
char **args;
args = _strtok(path, ":");
if (args == NULL)
return (NULL);
return (args);

}

/**
 * count_items_in_char_array - Counts the number of items in a char array.
 * @arr: The char array to be counted.
 * Return: The number of items in the char array.
*/

size_t count_items_in_char_array(char **arr)
{
size_t count = 0;
while (*arr != NULL)
{
count++;
arr++;
}
return (count);
}


/**
 * print_contents - Prints the contents of a char array.
 * @arr: The char array to be printed.
 * Return: void
*/

void print_contents(char **arr)
{
while (*arr != NULL)
{
printf("%s\n", *arr);
arr++;
}
}
/**
 * sig_handler - Prints a new prompt when the user presses Ctrl+C.
 * @sig: The signal number.
 * Return: void
*/

void sig_handler(int sig)
{
char *new_prompt = "\n$ ";

(void)sig;
signal(SIGINT, sig_handler);
write(STDIN_FILENO, new_prompt, 3);
}
