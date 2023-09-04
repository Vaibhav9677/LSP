#include"Fact_no.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    void (*fptr)(int (**)(int)) = NULL;
    char path[100] = {'\0'};
    int ret = 0;
    int (*Nest_ptr)(int) = NULL;

    if(argc != 2)
    {
        printf("Insufficients arguments..\n");
        exit(-1);
    }

    getcwd(path,sizeof(path));
    strcat(path,"/Nest_lib.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        return -1;
    }

    fptr = dlsym(ptr,"Get_add_fact");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        return -1;
    }

    fptr(&Nest_ptr);

    ret = Nest_ptr(atoi(argv[1]));
    printf("Factorial is : %d\n",ret);

    exit(0);
}

