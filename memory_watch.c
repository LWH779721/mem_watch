#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> 

//static void *true_malloc;
static void *(*true_malloc)(size_t);

void *malloc(size_t size)
{
    //static void *handl = NULL;
    
    //if (handl == NULL)
    //{
        //printf("1\n");
        //handl = dlopen("/lib/i386-linux-gnu/i686/cmov/libc.so.6", RTLD_LAZY);
        //printf("2\n");
        if (true_malloc == NULL)
        {    
            true_malloc = dlsym(RTLD_NEXT, "malloc");  
        }    
    //}
    printf("%s, %d, %d\n", __FILE__, __LINE__, size);     
    return true_malloc(size);   
}