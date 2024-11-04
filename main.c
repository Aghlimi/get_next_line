#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(int argc, char const *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    char* line;
    while (line = get_next_line(fd))
    {
        printf("%s",line);
        free(line);
    }
    
    return 0;
}
