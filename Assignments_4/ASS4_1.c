#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>


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


//provide directory name in input file(argv[1])

int main(int argc, char * argv[])
{
    int ret = 0;
    int fdin = 0, fdout = 0;
    DIR * DP = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char fname[300] = {'\0'};
    char Dname[20] = {'\0'};
    char ftype[20] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficients arguments...!\n");
        return -1;
    }

    fdin = open(argv[1],O_RDONLY);

    if(fdin == -1)
    {
        printf("Unable to open input file...\n");
        return -1;
    }

    fdout = open(argv[2],O_WRONLY | O_APPEND);

    if(fdout == -1)
    {
        printf("Unable to open output file..\n");
        return -1;
    }

    read(fdin,Dname,sizeof(Dname));

    DP = opendir(Dname);

    if(DP == NULL)
    {
        printf("Unable to open directory...!!\n");
        return -1;
    }
    
    while((entry = readdir(DP)) != NULL)
    {
        sprintf(fname,"%s/%s",Dname,entry->d_name);

        stat(fname,&sobj);

        ret = check_File_Type(&sobj);

        if(ret == 0)
        {
            strcpy(ftype,"Reguler File");   
        }
        else if(ret == 1)
        {
            strcpy(ftype,"Directory File");
        }
        else if(ret == 2)
        {
            strcpy(ftype,"Symblic File");
        }

        sprintf(fname,"%s : %s\n",entry->d_name,ftype);

        write(fdout,fname,strlen(fname));
    }

    closedir(DP);
    close(fdin);
    close(fdout);
    
    return 0;
}