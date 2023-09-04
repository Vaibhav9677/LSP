#include"File_fcn.h"
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

void Check_Files_Equal(char * file_1, char * file_2)
{
    int fd1 = 0, fd2 = 0;
    char Buffer1[BLOCKSIZE] = {'\0'};
    char Buffer2[BLOCKSIZE] = {'\0'};
    struct stat sobj1;
    struct stat sobj2;
    int ret = 0;

    fd1 = open(file_1,O_RDONLY);
    fd2 = open(file_2,O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("%s\n",strerror(errno));
        return;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are diffrents as size is diffrents..\n");
        return;
    }
    
    while(ret = read(fd1,Buffer1,sizeof(Buffer1)) != 0)
    {
        ret = read(fd2,Buffer2,sizeof(Buffer2));

        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret != 0)
    {
        printf("File are diffrents as a conatins are diffrents..\n");
        return;
    }
    else
    {
        printf("Files are identicals..\n");
    }

    exit(0);
}