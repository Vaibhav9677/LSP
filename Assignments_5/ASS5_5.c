#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

struct file_info
{
    char f_name[20];
    int f_size;
    int i_no;
    int link_count; 
    int n_blk;
};

int main(int argc, char *argv[])
{
    struct file_info fobj;
    char Fname[300];
    int fd = 0, fd1 = 0;
    int ret = 0;

    if(argc != 2)
    {
        printf("Insufficients arguments...\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open file..\n");
        return -1;
    }

    mkdir("New_Folder",0777);


    while((ret = read(fd,&fobj,sizeof(fobj))) != 0)
    {
        sprintf(Fname,"%s/%s","New_Folder",fobj.f_name);

        fd1 = creat(Fname,0777);

        if(fd1 == -1)
        {
            printf("%s : unable to craete file..\n",fobj.f_name);
        }
        else
        {
            printf("%s : file create successfully...",fobj.f_name);
        }
        
    }

    return 0;
}