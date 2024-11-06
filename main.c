#include "get_next_line.h"

int main()
{
    int i = 0;
    int fd = open("test.txt", O_RDONLY);
    char    *nextline;

    while((nextline = get_next_line(fd)))
    {
        printf("%s -> %d\n", nextline, i);
        i++;
    }
    free(nextline);
}