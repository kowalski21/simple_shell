#include "main.h"


/**
 * _getenv - get the environment variable
 * @name: name of env var
 * Return: A char pointer
*/

char *_getenv(char *name)
{
int i;
char *env_var, *equals_pos;
if (name == NULL || *name == '\0' || stringSearch(name, '=') != NULL)
return (NULL);
for (i = 0; environ[i] != NULL; i++)
{
env_var = environ[i];
equals_pos = stringSearch(env_var, '=');
if (equals_pos != NULL)
{
size_t name_length = equals_pos - env_var;
if (_strncmp(env_var, name, name_length) == 0 && name[name_length] == '\0')
return (equals_pos + 1);
}
}
return (NULL);
}

/**
 * free_environ - free environ
 * Return: void or nothing
*/
void free_environ(void)
{
int index;
for (index = 0; environ[index]; index++)
free(environ[index]);
free(environ);
}
