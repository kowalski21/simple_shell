#include "main.h"

/**
 * char *_strcpy - a simple function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}


/**
 * _strncpy - to copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}

/**
 * _strcspn - to copy a string
 * @str1: str1
 * @str2: str2
 *
 *
 * Return: diff in string length
 */

size_t _strcspn(char *str1, char *str2)
{
size_t len = 0;
while (str1[len] != '\0')
{
size_t i = 0;
while (str2[i] != '\0')
{
if (str1[len] == str2[i])
{
return (len);
}
i++;
}
len++;
}
return (len);
}
