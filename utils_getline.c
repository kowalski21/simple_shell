#include "main.h"


/**
* reassign_ptr - fixes given pointer
* @buffer: pointer to buffer
* @n: reference size
* @ptr: initial pointer
* @fixer: Fixer integer
*/

void reassign_ptr(char *buffer, size_t *n, char **ptr, size_t fixer)
{
if (*ptr == NULL)
{
if (fixer > 120)
*n = fixer;
else
*n = 120;
*ptr = buffer;
}
else if (*n > fixer)
{
if (fixer > 120)
*n = fixer;
else
*n = 120;

*ptr = buffer;
}
else
{
_strcpy(*ptr, buffer);
free(buffer);
}
}
