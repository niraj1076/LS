//write a program which accepts the name of directory and a name of a file from user and cheack if that file is present or not.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[50];
    struct stat sobj;
    char DirName[40];

    printf("Enter directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s", DirName, entry -> d_name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                remove(name);
            }
        }   
    }

    closedir(dp);
    return 0;
}