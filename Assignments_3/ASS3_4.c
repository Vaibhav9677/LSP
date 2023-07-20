#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    DIR * DP = NULL;
    struct stat sobj;
    struct dirent * entry = NULL;
    char fname[300] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficients arguments...!\n");
        return -1;
    }

    DP = opendir(argv[1]);

    if(DP == NULL)
    {
        printf("Unable to open directory...!!\n");
        return -1;
    }

    
    while((entry = readdir(DP)) != NULL)
    {
        sprintf(fname,"%s/%s",argv[1],entry->d_name);

        stat(fname,&sobj);

        if(sobj.st_size == 0)
        {
            remove(fname);
        }   
    }

    closedir(DP);
    return 0;
}