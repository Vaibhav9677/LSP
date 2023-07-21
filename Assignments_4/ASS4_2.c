#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int ret = 0;

    if(argc != 2)
    {
        printf("Insuffienets arguments....!!!\n");
        return -1;
    }

    ret = mkdir(argv[1],0777);

    if(ret == -1)
    {
        printf("Unable to create directory....!!\n");
        return -1;
    }
    else
    {
        printf("Directory created successfully...\n");
    }

    return 0;
}