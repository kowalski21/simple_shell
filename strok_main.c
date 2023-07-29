#include "main.h"


/**
 * _strtok - My own strtok
 * @str: The string
 * @delimeter: The delimeter
 * Return: A pointer to array of tokenized string
*/
char **_strtok(char *str, char *delimeter)
{
char **holder;
int index = 0, token_count, t, letters, l;
token_count = tokenCounter(delimeter, str);
if (token_count == 0)
return (NULL);

holder = malloc(sizeof(char *) * (token_count + 2));
if (!holder)
return (NULL);
for (t = 0; t < token_count; t++)
{
while (str[index] == *delimeter)
index++;
letters = tokenLength(delimeter, str + index);
holder[t] = malloc(sizeof(char) * (letters + 1));
if (!holder[t])
{
for (index -= 1; index >= 0; index--)
free(holder[index]);
free(holder);
return (NULL);
}
for (l = 0; l < letters; l++)
{
holder[t][l] = str[index];
index++;
}
holder[t][l] = '\0';
}
holder[t] = NULL;
holder[t + 1] = NULL;
return (holder);
}
