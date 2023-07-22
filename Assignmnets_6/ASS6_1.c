#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


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
    struct stat sobj;
    int fd = 0;
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

    printf("File name whose size is greater then 10 byte : \n");

    while((ret = read(fd,&fobj,sizeof(fobj))) != 0)
    {
        stat(fobj.f_name,&sobj);

        if(sobj.st_size > 10)
        {
            printf("%s\n",fobj.f_name);
        }
        
    }

    return 0;
}