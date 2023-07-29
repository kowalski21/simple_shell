#include "main.h"


int stringLength(const char *str);
char *stringConcat(char *destination, char *source);

/**
 * stringLength - Returns the length of a given string
 * @str: A pointer to the string character
 * Return: The number of characters in the string
*/
int stringLength(const char *str)
{
int len = 0;
if (!str)
{
return (0);
}
while (*str != '\0')
{
len++;
str++;
}
return (len);
}

/**
 * stringConcat - concats 2 strings.
 * @destination: A pointer to dest string.
 * @source: A pointer to src string.
 *
 * Return: A pointer to new string
 */
char *stringConcat(char *destination, char *source)
{
char *dest = destination;
while (*dest != '\0')
dest++;


while (*source != '\0')
{
*dest = *source;
dest++;
source++;
}
*dest = '\0';
return (destination);
}

/**
 * stringBytesConcat - Concats based bytes given
 * @dest: A pointer to dest string
 * @src: A pointer to src string
 * @num: Number of bytes to copy
 * Return: A pointer to the new string
*/

char *stringBytesConcat(char *dest, char *src, size_t num)
{
size_t counter;
size_t destLength = stringLength(dest);
for (counter = 0; counter < num && src[counter] != '\0'; counter++)
dest[destLength + counter] = src[counter];

dest[destLength + counter] = '\0';

return (dest);
}


