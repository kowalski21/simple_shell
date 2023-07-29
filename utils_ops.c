#include "main.h"

/**
 * findCommandPath - Finds the path of the given command.
 * @cmd: The command to be found.
 * @pathArray: The array of paths to be searched.
 * @numPaths: The number of paths in the array.
 * Return: The path of the command if found, NULL otherwise.
*/
char *findCommandPath(char *cmd, char **pathArray, int numPaths)
{
size_t totalLength = 0;
int i;
char *result;
for (i = 0; i < numPaths; i++)
{
totalLength = stringLength(pathArray[i]) + stringLength(cmd) + 2;
result = (char *)malloc(totalLength);
if (result == NULL)
return (NULL);
_strcpy(result, pathArray[i]);
stringConcat(result, "/");
stringConcat(result, cmd);
if (access(result, F_OK) == 0)

return (result);
free(result);
}
return (NULL);
}

/**
 * isValidFilePath - Checks if the given file path is valid.
 * @filePath: The file path to be checked.
 * Return: 1 if the file path is valid, 0 otherwise.
*/
int isValidFilePath(char *filePath)
{
if (access(filePath, F_OK) == 0)
return  (1);

return (0);
}


/**
 * freeArgsArray - Frees the memory allocated for the array of char*.
 * @array: The array of char* to be freed.
 * @size: The size of the array.
 * Return: void
*/

void freeArgsArray(char **array, int size)
{
int i;
if (array == NULL)
return;
for (i = 0; i < size; i++)
{
if (array[i] != NULL)
{
free(array[i]);
array[i] = NULL;
}
}
free(array);
}


/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 * Return: The pointer to the duplicated string.
*/

char *_strdup(char *str)
{
size_t len;
char *duplicate;
if (str == NULL)
return (NULL);
len = stringLength(str) + 1;
duplicate = (char *)malloc(len);
if (duplicate != NULL)
_strcpy(duplicate, str);
return (duplicate);
}
