//write a program which accepts the directory name from user and print all file name and if type from that directory.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;



    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        printf("the file name : %s and its type is :%d\n",entry ->d_name ,entry ->d_type);
    }

    closedir(dp);

    return 0;
}