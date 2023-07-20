#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    char fname[300] = {'\0'};

    if(argc != 3)
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
        if((strcmp(entry->d_name,argv[2])) == 0)
        {
            printf("%s is present in the directory..!\n",entry->d_name);
            break;
        }

    }

    if(entry == NULL)
    {
        printf("%s : There is no such file..!!\n",argv[2]);
        return -1;
    }
    closedir(DP);
    return 0;
}