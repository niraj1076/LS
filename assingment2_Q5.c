//write a program which accepts the name of directory from user and print the name of file with largest size.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;

    printf("Enter the directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName ,entry -> d_name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(namecopy, name);
            }
        }
    }

    printf("Name of the largest file : %s with size %d bytes\n",namecopy,iMax);
    
    closedir(dp);
    return 0;
}