//write a program which accepts directory name from user and create new directory of the name .
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/dir.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int Ret = 0;

    if(argc != 2)
    {
        printf("Insufficent arguments\n");
    }

    Ret = mkdir(argv[1], 0755);
    if(Ret != 0)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    else
    {
        printf("Directory created succesfully of %s\n", argv[1]);
    }

    return 0;
}