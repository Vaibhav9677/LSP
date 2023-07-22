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
    struct stat sobj;
    struct file_info fobj;
    DIR *DP = NULL;
    struct dirent * entry = NULL;
    char Fname[300];
    int fd = 0;
    int ret = 0;

    if(argc != 2)
    {
        printf("Insufficients arguments...\n");
        return -1;
    }


    DP = opendir(argv[1]);

    if(DP == NULL)
    {
        printf("Unable to open directory...\n");
        return -1;
    }

    fd = creat("Directory_Info.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create directory_Info.txt file...\n");
        return -1;
    }

    while((entry = readdir(DP)) != NULL)
    {
        sprintf(Fname,"%s/%s",argv[1],entry->d_name);

        stat(Fname,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            strcpy(fobj.f_name,entry->d_name);
            fobj.f_size = sobj.st_size;
            fobj.i_no = sobj.st_ino;
            fobj.link_count = sobj.st_nlink;
            fobj.n_blk = sobj.st_blocks;

            write(fd,&fobj,sizeof(fobj));
        }
    }

    close(fd);

    fd = open("Directory_Info.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("unable t read..\n");
        return -1;
    }

    printf("Information of all file from %s directory : \n");

    while((ret = read(fd,&fobj,sizeof(fobj))) != 0)
    {
        printf("File name : %s\n",fobj.f_name);
        printf("Inode number : %d\n",fobj.i_no);
        printf("Number of links : %d\n",fobj.link_count);
        printf("Size of file : %d\n",fobj.f_size);
        printf("Number of block : %d\n",fobj.n_blk);
        printf("\n");
    }

    return 0;
}