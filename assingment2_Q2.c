//write a program which accepts the name of file from user and write a string in that file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char string[30] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficent Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    scanf("%[^'\n']s", string);

    Ret = write(fd,string,30);
    if(Ret == -1)
    {
        printf("Unable to write data in file\n");
        return -1;
    }

   
    close(fd);
    return 0;
}