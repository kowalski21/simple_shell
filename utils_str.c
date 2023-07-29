#include "main.h"

/**
 * _strncmp - compare n strings
 * @s1: s1
 * @s2: s2
 * @n: size n
 * Return: matched string
*/
int _strncmp(char *s1, char *s2, size_t n)
{
size_t i = 0;
while (s1[i] != '\0' && s2[i] != '\0' && i < n)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
}
if (i == n)
return (0);
else
return (s1[i] - s2[i]);
}
