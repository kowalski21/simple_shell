#include "main.h"

/**
 * tokenLength - Find the delimeter
 * @delimeter: The delimeter character
 * @str: The string with delimeters
 * Return:return the token index
*/

int tokenLength(char *delimeter, char *str)
{
int initLength = 0;
int  trackIndex = 0;

while (*(str + trackIndex) != *delimeter && *(str + trackIndex))
{
trackIndex++;
initLength++;
}

return (initLength);
}

/**
 * tokenCounter - Count the number of tokens in a string
 * @delimeter: The delimeter
 * @str: The String
 * Return: the number of tokens in a string;
*/

int tokenCounter(char *delimeter, char *str)
{
int tokenCount = 0;
int tracker, len = 0;

for (tracker = 0; *(str + tracker); tracker++)
len++;
for (tracker = 0; tracker < len; tracker++)
{
if (*(str + tracker) != *delimeter)
{
tokenCount++;

tracker = tracker + tokenLength(delimeter, str + tracker);
}
}
return (tokenCount);
}

/**
 * freeTokens - Free pointer to pointer of strings
 * @tokens: Tokens to free
 * Return: void
*/
void freeTokens(char **tokens)
{
int i;
if (tokens == NULL)
return;
for (i = 0; tokens[i] != NULL; i++)
{
free(tokens[i]);
tokens[i] = NULL;
}
free(tokens);
}
