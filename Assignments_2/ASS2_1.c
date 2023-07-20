#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#define BLOCK_SIZE 1024

int main(int argc, char * argv[])
{
    int fd = 0;
    int ret = 0;
    char * Buffer = NULL;

    if(argc != 2)
    {
        printf("Insufficients Arguments..\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unbale to open file ...\n");
        return -1;
    }

    Buffer = (char *)malloc(BLOCK_SIZE);

    if(Buffer == NULL)
    {
        printf("Unable to read file...!\n");
        return -1;
    }

    printf("Data from file is : \n");

    while((ret = read(fd,Buffer,BLOCK_SIZE)) != 0)
    {
        write(1,Buffer,ret);
    }

    printf("\n");

    return 0;
}