#include "get_next_line.h"

char	*get_next_line(int fd)
{
    int     finish;
    char    *buffer;
    char    *printed;

    finish = 0;
    while (finish == 0)
    {
        buffer = ft_allocate(BUFFER_SIZE);
        finish = copy(/*recup fd*/, buffer);
        printed = ft_putstr(buffer);
        //call ft_free tba here
    }
}

int copy(char *str, char *buffer)
{
    int i;

    i = 0;
    while (str[i] != 0 && i < BUFFER_SIZE)
    {
        buffer[i] = str[i];
        if (buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}