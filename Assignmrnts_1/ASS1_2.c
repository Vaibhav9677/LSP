#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int mode = 0;


    if(argc != 3)
    {
        printf("Invalied Arguments...!\n");
        printf("Read : read\nWrite : write\nRead_Wite : RW\n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"RW") == 0)
    {
        mode = O_RDWR;
    }
    else
    {
        mode = O_RDONLY;
    }

    fd = open(argv[1], mode);

    if(fd == -1)
    {
        printf("Unable to open file ....!!\n");
        return -1;
    }
    else
    {
        printf("File : %s open succesfully with fd : %d in %s mode..!\n",argv[1],fd,argv[2]);
    }

    return 0;
}