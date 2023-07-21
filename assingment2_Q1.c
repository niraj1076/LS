//write a program which accepts the name of file from user and read that whole file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    int iSize = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Insufficent Arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to ipen file\n");
        return -1;
    }

    while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        write(1, Buffer, Ret);
    }
   
    close(fd);
    return 0;
}