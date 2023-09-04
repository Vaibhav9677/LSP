#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>
#include<unistd.h>
#include"Arithmetic.h"

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    int (*fptr)(int, int) = NULL;
    float (*dptr)(int, int) = NULL;
    int iret = 0;
    float dret = 0.0;
    char path[100] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficients Arguments....Pass two number as a command line arguments\n");
        exit(-1);
    }

    getcwd(path,sizeof(path));
    strcat(path,"/Arithmetic.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr = dlsym(ptr,"Addition");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    
    
    iret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Addition is : %d\n",iret);
    

    fptr = dlsym(ptr,"Subtraction");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    
    
    iret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Subtraction is : %d\n",iret);
    

    fptr = dlsym(ptr,"Multiplication");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    
    iret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Multiplication is : %d\n",iret);
    

    dptr = dlsym(ptr,"Division");

    if(dptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    dret = dptr(atoi(argv[1]),atoi(argv[2]));
    printf("Division is : %f\n",dret);
    

    exit(-1);
}