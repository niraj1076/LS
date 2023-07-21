//write a program which accepts the directory name from user and print all file name from that directory.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Insufficemt arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    printf("----------------------------------------------------------------\n");
    printf("Entries from the directory file are :\n");
    printf("----------------------------------------------------------------\n");
    printf(" File name \t\t iNode number \n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s : %d\n", entry -> d_name, entry -> d_ino);
    }

    printf("----------------------------------------------------------------\n");


    closedir(dp);    
    return 0;
}