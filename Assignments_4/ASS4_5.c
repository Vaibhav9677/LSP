#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//#include<sys/stat.h>
//#include<dirent.h>
#include<string.h>

#define BLOCK_SIZE 20

int main(int argc, char * argv[])
{
    int ret = 0, fd = 0;
    
    char Buffer[BLOCK_SIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficients arguments...!\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file...!\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),SEEK_SET);

    ret = read(fd,Buffer,BLOCK_SIZE);

    write(1,Buffer,ret);
    printf("\n");

    return 0;
}