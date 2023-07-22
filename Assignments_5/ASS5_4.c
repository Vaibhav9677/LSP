#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define BLOCK_SIZE 1024

int main(int argc, char * argv[])
{
    int ret = 0, fd = 0, fdread = 0;
    DIR * Dp = NULL;
    struct stat sobj;
    struct dirent * entry = NULL;
    char fname[300] = {'\0'};
    char Buffer[BLOCK_SIZE] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficients arguments...!\n");
        return -1;
    }

    Dp = opendir(argv[1]);

    if(Dp == NULL)
    {
        printf("%s : Unable to open directory....!\n",argv[1]);
        return -1;
    }

    fd = creat("All_combine.txt",0777);

    if(fd  == -1)
    {
        printf("All_combine : Unable to create file....\n");
        return -1;
    }

    while((entry = readdir(Dp)) != NULL)
    {
        sprintf(fname,"%s/%s",argv[1],entry->d_name);

        stat(fname,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fdread = open(fname,O_RDONLY);

            if(fdread == -1)
            {
                printf("%s : Unbale to open file..\n",entry->d_name);
                break;
            }
            else
            {
                printf("File open\n");
            }

            while((ret = read(fdread,Buffer,BLOCK_SIZE)) != 0)
            {
                write(fd,Buffer,ret);
            }

            if(ret == 0)
            {
                close(fdread);
            }

        }
    }


    if(entry != NULL)
    {
        printf("Error : unable to open some fils...!\n");  
    }

    close(fd);
    closedir(Dp);
    
    return 0;
}