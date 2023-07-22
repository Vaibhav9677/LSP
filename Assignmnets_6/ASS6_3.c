#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char fname[300] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficients arguments..\n");
        return -1;
    }

    sprintf(fname,"%s/%s",argv[1],argv[2]);

    fd = creat(fname,0777);

    if(fd == -1)
    {
        printf("Unbale to create file.....\n");
        return -1;
    }
    else
    {
        printf("File Successfully create with fd : %d\n",fd);
    }

    return 0;
}