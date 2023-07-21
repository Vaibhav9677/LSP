#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define BLOCK_SIZE 10

int main(int argc, char * argv[])
{
    int ret = 0, fd = 0, fdread = 0;
    DIR * Dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
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

    fd = creat("Demo1.txt",0777);

    if(fd  == -1)
    {
        printf("Demo.txt : Unable to create file....\n");
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

            ret = read(fdread,Buffer,BLOCK_SIZE);
        
            write(fd,Buffer,ret);

            memset(Buffer,0,BLOCK_SIZE);
        }
    }

    if(entry != NULL)
    {
        printf("Error : unable to open some fils...!\n");  
    }
    
    return 0;
}