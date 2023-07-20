#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

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

    fd = open(argv[1],O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        printf("Unbale to open file ...\n");
        return -1;
    }

    Buffer = (char *)malloc(20);

    if(Buffer == NULL)
    {
        printf("Unable to read file...!\n");
        return -1;
    }

    printf("Enter the string : \n");
    scanf("%[^\n]",Buffer);

    //printf("%s",Buffer);

    ret = write(fd,Buffer,strlen(Buffer));

    if(ret == -1)
    {
        printf("Uable to write data into the file..!!\n");
        return -1;
    }
    else
    {
        printf("Data write succesfully in the file ....\n");
        close(fd);
    }

    return 0;
}