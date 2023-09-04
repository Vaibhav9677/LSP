#include"File_info.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("Insufficients arguments..\n");
        exit(-1);
    }

   Display_File_info(argv[1]);

    exit(0);
}

