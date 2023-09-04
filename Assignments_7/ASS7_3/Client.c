#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<dlfcn.h>
#include<string.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    bool (*fptr)(int) = NULL;
    char path[100] = {'\0'};
    bool bret = 0;

    if(argc != 2)
    {
        printf("Insufficients arguments..\n");
        exit(-1);
    }

    getcwd(path,sizeof(path));
    strcat(path,"/Ch_prime.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr = dlsym(ptr,"check_Prime");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    bret = fptr(atoi(argv[1]));

    if(bret == true)
    {
        printf("%d : is prime number\n",atoi(argv[1]));
    }
    else
    {
        printf("%d : is not a prime number\n",atoi(argv[1]));
    }

    memset(path,0,sizeof(path));
    getcwd(path,sizeof(path));
    strcat(path,"/Ch_perfect.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr = dlsym(ptr,"check_Perfect");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    bret = fptr(atoi(argv[1]));

    if(bret == true)
    {
        printf("%d : is a perfect number\n",atoi(argv[1]));
    }
    else
    {
        printf("%d : is not a perfect number\n",atoi(argv[1]));
    }

    exit(0);
}