#include<stdio.h>
#include<unistd.h>
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

int main(int argc, char * argv[])
{
    struct stat sobj;
    int ret = 0;
    int retc =0;

    if(argc != 2)
    {
        printf("Insuffcient arguments...\n");
        return -1;
    }

    ret = stat(argv[1],&sobj);

    if(ret == -1)
    {
        printf("Unable to display information..!!\n");
        return -1;
    }
    
    
    printf("Information of file : \n");\
    printf("Name : %s\n",argv[1]);
    printf("Device : %d\n",sobj.st_dev);
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
    
    printf("Inode number : %d\n",sobj.st_ino);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("User ID : %d\n",sobj.st_uid);
    printf("Size of file : %d\n",sobj.st_size);
    printf("Number of block : %d\n",sobj.st_blocks);
    

    return 0;
}
