//Write a program which accepts file name and mode from user and open the file in that specfic mode.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid numbers of arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDWR;
    }

    fd = open(argv[1], Mode);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else
    {
        printf("File open succesfully with FD : %d\n", fd);
    }

    close(fd);

    return 0;
}