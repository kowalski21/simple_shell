#include "main.h"

/**
 * stringSearch - Search string for char
 * @str: String to search
 * @c: Character String to search
 * Return: if c return pointer else return NULL
*/

char *stringSearch(char *str, char c)
{
int counter;
for (counter = 0; str[counter]; counter++)
{
if (str[counter] == c)
{
return (str + counter);
}
}
return (NULL);
}


/**
 * stringCompare - how to compare string values
 * @s1: first string value
 * @s2: second string value
 *
 * Return: s1[i] - s2[i]
 */
int stringCompare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * searchSubString - Searches for substring in string
 * @haystack: input
 * @needle: input
 * Return: Always 0 (Success)
 */
char *searchSubString(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *l = haystack;
		char *p = needle;

		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}



/**
 * _strpbrk - Search for substring occurrence
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
		int k;

		while (*s)
		{
			for (k = 0; accept[k]; k++)
			{
			if (*s == accept[k])
			return (s);
			}
		s++;
		}

	return ('\0');
}

