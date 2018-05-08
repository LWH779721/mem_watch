#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **args)
{
    char *buf;
    
    if (NULL == (buf = malloc(sizeof(char) *100)))
    {
        printf("malloc failed\n");
        return -1;
    }
    
    free(buf);
    return 0;
}