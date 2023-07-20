#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int mode = 0;
    int ret = 0;

    if(argc != 3)
    {
        printf("Insfficients Arguments..\n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        mode = R_OK;
    }
    else if(strcmp(argv[2], "write") == 0)
    {
        mode = W_OK;
    }
    else if(strcmp(argv[2],"execute") == 0)
    {
        mode = X_OK;
    }
    else
    {
        printf("Invaild Arguments..\n");
        printf("Pass file name as a command line along with access mode as follow..:\n");
        printf("Read mode : read\n");
        printf("Write mode : write\n");
        printf("Execute mode : execute\n");
        return -1;
    }

    ret = access(argv[1],mode);

    if(ret == 0)
    {
        printf("%s is able to access in %s mode...\n",argv[1],argv[2]);
    }
    else
    {
        printf("ACCESS DENIDE.....!!!\n");
        return -1;
    }
    return 0;
}