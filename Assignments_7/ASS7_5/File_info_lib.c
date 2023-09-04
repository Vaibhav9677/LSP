#include"File_info.h"
#include<stdio.h>
#include<sys/stat.h>

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

void Display_File_info(char * filename)
{
    struct stat sobj;
    int ret = 0;
    int retc =0;

    ret = stat(filename,&sobj);

    if(ret == -1)
    {
        printf("Unable to display information..!!\n");
        return;
    }
    
    
    printf("Information of file : \n");\
    printf("Name : %s\n",filename);
    printf("Device : %ld\n",sobj.st_dev);
    printf("File Type : ");
    retc = check_File_Type(&sobj);

    if(retc == 0)
    {
        printf("Regular\n");
    }
    else if(retc == 1)
    {
        printf("Directory\n");
    }
    else if(retc == 2)
    {
        printf("Symblic\n");
    }
    else
    {
        printf("Unkown\n");
    }
    
    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Number of links : %ld\n",sobj.st_nlink);
    printf("User ID : %d\n",sobj.st_uid);
    printf("Size of file : %ld\n",sobj.st_size);
    printf("Number of block : %ld\n",sobj.st_blocks);

    return;
}

