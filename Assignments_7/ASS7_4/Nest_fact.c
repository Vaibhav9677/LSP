#include"Fact_no.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>
#include<unistd.h>

void Get_add_fact(int(**fptr_1)(int))
{
    void * ptr = NULL;
    int (*fptr)(int) = NULL;
    char path[100] = {'\0'};

    getcwd(path,sizeof(path));
    strcat(path,"/Fact_lib.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        return;
    }

    fptr = dlsym(ptr,"Fact_Number");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        return;
    }

    *(fptr_1) = fptr;

    return;
}

