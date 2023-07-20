#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficients Arguments...!\n");
        printf("Please enter file name as a command line arguments..\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file ....!!\n");
        return -1;
    }
    else
    {
        printf("File : %s open succesfully with fd : %d\n",argv[1],fd);
    }

    return 0;
}