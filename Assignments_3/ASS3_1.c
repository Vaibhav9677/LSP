#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCK_SIZE 1024

int main(int argc, char * argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;

    char Buffer[BLOCK_SIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("%s : File dose't exits...!!\n",argv[1]);
        return -1;
    }

    fd2 = open(argv[2], O_WRONLY);

    if(fd2 == -1)
    {
        fd2 = creat(argv[2],0777);
    }
    else
    {
        printf("%s : File alredy exits..!!\n",argv[2]);
        return -1;
    }


    while((ret = read(fd1,Buffer,BLOCK_SIZE)) != 0)
    {
        write(fd2,Buffer,ret);
        memset(Buffer,0,BLOCK_SIZE);
    }

    if(ret == 0)
    {
        printf("File Successfully coped..\n");
    }

    return 0;
}