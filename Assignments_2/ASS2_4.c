#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>


int check_File_Type(struct stat * pstat)
{
    if(S_ISREG(pstat->st_mode))
    {
        return 0;
    }
    else if(S_ISDIR(pstat->st_mode))
    {
        return 1;
    }
    else if(S_ISLNK(pstat->st_mode))
    {
        return 2;
    }    
}

int main(int argc, char * argv[])
{
    int ret = 0;
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char fname[300] = {'\0'};
    char ftype[20] = {'\0'};

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
    printf("File name in %s directory and its type are:\n",argv[1]);
    printf("-------------------------------------------\n");

    printf("\t  File name : File Type\n");

    printf("-------------------------------------------\n");
    
    while((entry = readdir(DP)) != NULL)
    {
        sprintf(fname,"%s/%s",argv[1],entry->d_name);

        stat(fname,&sobj);

        ret = check_File_Type(&sobj);

        if(ret == 0)
        {
            strcpy(ftype,"Reguler File");   
        }
        else if(ret == 1)
        {
            strcpy(ftype,"Directory File");
        }
        else if(ret == 2)
        {
            strcpy(ftype,"Symblic File");
        }

        printf("%20s : %s\n",entry->d_name,ftype);
    }

    printf("-------------------------------------------\n");

    closedir(DP);
    return 0;
}