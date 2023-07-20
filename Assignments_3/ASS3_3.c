#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    char OLD_Name[300] = {'\0'};
    char NEW_Name[300] = {'\0'};
    
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
        sprintf(OLD_Name,"%s/%s",argv[1],entry->d_name);
        sprintf(NEW_Name,"%s/%s",argv[2],entry->d_name);

        rename(OLD_Name,NEW_Name);
    }

    if(entry == NULL)
    {
        printf("ALL file MOVED successfully...!!\n");

    }
    
    closedir(DP);
    return 0;
}