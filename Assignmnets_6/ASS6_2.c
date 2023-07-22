#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char Buffer[10] = {"Vaibhav"};
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficients arguments..\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file .\n");
        return -1;
    }

    lseek(fd,1024,SEEK_END);

    write(fd,Buffer,sizeof(Buffer));

    return 0;
}