#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCK_SIZE 1024

int main(int argc, char * argv[])
{
    int ret = 0;
    int fd = 0;
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;

    char fname[300] = {'\0'};
    char Buffer[BLOCK_SIZE] = {'\0'};


    if(argc != 2)
    {
        printf("Insufficients arguments....\n");
        return -1;
    }

    DP =opendir(argv[1]);

    if(DP == NULL)
    {
        printf("Unable to open directory...\n");
        return -1;
    }

    while((entry = readdir(DP)) != NULL)
    {
        sprintf(fname,"%s/%s",argv[1],entry->d_name);

        stat(fname,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > BLOCK_SIZE)
            {
                ret = truncate(fname,BLOCK_SIZE);

                if(ret == -1)
                {
                    printf("%s : Unable to truncate file...\n",entry->d_name);
                    continue;
                }
            }
            else
            {
                fd = open(fname,O_WRONLY);

                if(fd == -1)
                {
                    printf("%s : unable to open file....\n",entry->d_name);
                    continue;
                }

                lseek(fd,0,SEEK_END);

                write(fd,Buffer,BLOCK_SIZE);
            }
        }
    }

    return 0;
}