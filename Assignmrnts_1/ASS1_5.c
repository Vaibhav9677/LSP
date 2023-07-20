#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int ret = 0;
    char * Buffer = NULL;

    if(argc != 3)
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

    Buffer = (char *)malloc((atoi(argv[2])));

    if(Buffer == NULL)
    {
        printf("Unable to read file...!\n");
        return -1;
    }

    ret = read(fd,Buffer,atoi(argv[2]));

    if(ret == 0)
    {
        printf("Ubale to read data from file ..\n");
        return -1;
    }

    printf("Data from file is : \n");

    write(1,Buffer,ret);

    return 0;
}