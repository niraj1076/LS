//write a program which accept file name from user and print all information about that file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficent Arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    fstat(fd, &sobj);

    printf("File Name : %s\n", argv[1]);
    printf("File size : %d\n", sobj.st_size);
    printf("Inode Number : %d\n", sobj.st_ino);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Number of blocks : %d\n", sobj.st_blocks);
    

    return 0;
}