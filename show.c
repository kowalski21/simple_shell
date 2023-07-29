#include "main.h"

/**
 * print_args - print contents of pointer arr
 * @num: Number of args
 * @av: pointer of arr
 * Return: returns an integer;
*/

int  print_args(int num, char **av)
{
int i;
int length = 0;
for (i = 1; i < num; i++)
{
while (av[i][length] != '\0')
length++;
write(STDOUT_FILENO, av[i], length);
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}
