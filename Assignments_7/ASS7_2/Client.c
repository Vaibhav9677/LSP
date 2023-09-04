#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>
#include<string.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    int (*fptr)(char *,char *) = NULL;
    char path[100] = {'\0'};
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficients arguments..\n");
        exit(-1);
    }

    getcwd(path,sizeof(path));
    strcat(path,"/file_fcn.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr = dlsym(ptr,"Check_Files_Equal");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr(argv[1],argv[2]);

    exit(0);
}