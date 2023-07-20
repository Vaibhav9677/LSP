#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    DIR * DP = NULL;
    struct dirent * entry = NULL;

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

    printf("-------------------------------------------\n");
    printf("File name in %s directory :\n",argv[1]);
    printf("-------------------------------------------\n");
    
    while((entry = readdir(DP)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }

    printf("-------------------------------------------\n");

    closedir(DP);
    return 0;
}