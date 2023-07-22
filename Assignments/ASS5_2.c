#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct employee
{
    int eno;
    char ename[20];
    float salary;
    int Age;
};

int main(int argc, char *argv[])
{
    struct employee sobj;
    char Fname[20];
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
        printf("Unable to open file ..\n");
        return -1;
    }

    printf("Data of employee from file is : \n");

    while((ret = read(fd,&sobj,sizeof(sobj))) != 0)
    {
        printf("Emp number of employee : %d\n",sobj.eno);
        printf("Emp name of employee : %s\n",sobj.ename);
        printf("salary of employee : %f\n",sobj.salary);
        printf("Age of employee : %d\n",sobj.Age);
        printf("\n");
    }

    return 0;
}