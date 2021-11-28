#include "get_next_line.h"

char    *ft_putstr(char *str)
{
    int i;

    if (str == NULL)
    {
        write (1, "NULL", 4);
        return (NULL);
    }
    
    i = 0;
    while (str[i] != 0)
        i++;
    write(1, str, i);
    return (str);
}

void    *ft_allocate(int buffer)
{
    void    *mem;

    if (buffer == 0)
    {
        mem = malloc(0);
        return (mem);
    }
    mem = malloc(sizeof(char) * buffer);
    if (!mem)
        return (NULL);
    return (mem);
}
