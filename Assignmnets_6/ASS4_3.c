#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCK_SIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;

    char Buffer1[BLOCK_SIZE] = {'\0'};
    char Buffer2[BLOCK_SIZE] = {'\0'};     

    struct stat sobj1;
    struct stat sobj2;

    if(argc != 3)
    {
        printf("Insufficients arguments...\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open files....\n");
        return -1;
    }

    stat(argv[1],&sobj1);
    stat(argv[2],&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are differents as there size are differents...\n");
        return -1;
    }


    while((ret = read(fd1,Buffer1,BLOCK_SIZE)) != 0)
    {
        ret = read(fd2,Buffer2,BLOCK_SIZE);

        if((memcmp(Buffer1,Buffer2,ret)) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("File are identical...\n");
    }
    else
    {
        printf("file are diffrents..\n");
    }

    return 0;
}