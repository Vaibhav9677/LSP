#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficients arguments....\n");
        return -1;
    }

    ret = truncate(argv[1],atoi(argv[2]));

    if(ret == -1)
    {
        printf("Unable to remove data from file....\n");
        return -1;
    }
    else
    {
        printf("Data from file remove successfully....\n");
    }

    return 0;
}