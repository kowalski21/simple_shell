#include "main.h"

/**
* _realloc - memory reallocation
* @ptr: Pointer
* @old_size: pointer memeroy allocation
* @new_size: New memory size
* Return: a pointer void to be cast
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *void_mem;
char *copy_ptr;
char *exe_ptr;
ssize_t  index;
if (old_size == new_size)
return (ptr);
if (ptr == NULL)
{
void_mem = malloc(new_size);
if (void_mem == NULL)
return (NULL);
return (void_mem);
}
if (ptr != NULL && new_size == 0)
{
free(ptr);
return (NULL);
}
copy_ptr = ptr;
void_mem = malloc(sizeof(*copy_ptr) * new_size);
if (void_mem == NULL)
{
free(ptr);
return (NULL);
}
exe_ptr = void_mem;
for (index = 0; index < new_size && index < old_size; index++)
exe_ptr[index] = *copy_ptr++;

free(ptr);
return (void_mem);
}

/**
 * _getline - get input from stream
 * @lineptr: buffer to store input
 * @n: buffer size
 * @stream: input stream
 * Return: Number of bytes read
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
ssize_t ret;
static ssize_t input;
int read_status;
char *buffer;
char checkC = 'x';

if (input == 0)
fflush(stream);
else
return (-1);
input = 0;
buffer = malloc(sizeof(char) * 120);
if (!buffer)
return (-1);
while (checkC != '\n')
{
read_status = read(STDIN_FILENO, &checkC, 1);
if (read_status == -1 || (input == 0 && read_status == 0))
{
free(buffer);
return (-1);
}
if (input >= 120)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = checkC;
input++;
}
buffer[input] = '\0';

reassign_ptr(buffer, n, lineptr, input);
ret = input;
if (read_status != 0)
input = 0;

return (ret);
}
