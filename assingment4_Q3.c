//write a program which accept 2 fiel name from user and check wheather the content of the file are same or not.
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, Ret  = 0;
    struct stat sobj1, sobj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];
    int iCnt = 0;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1, &sobj1);
    fstat(fd2, &sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("File are of diffrent sizes\n");
        return -1;
    }

    while((Ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        Ret = read(fd2, Buffer2, sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,Ret) != 0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        printf("Both file are identical\n");
    }
    else
    {
        printf("Both file are diffrent\n");
    }

    return 0;
}