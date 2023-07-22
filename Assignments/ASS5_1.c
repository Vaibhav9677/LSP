#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;

    printf("Enter the roll number of student : \n");
    scanf("%d",&sobj.Rollno);

    printf("Enter the name of student : \n");
    scanf("%s",sobj.Sname);

    printf("Enter the mark of student : \n");
    scanf("%f",&sobj.Marks);

    printf("Enter the age of student : \n");
    scanf("%d",&sobj.Age);

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&sobj,sizeof(sobj));

    return 0;
}