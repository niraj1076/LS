//Write a program which accepts file name from user and open the file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Fname[30];

    printf("Enter the name of file to open \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else
    {
        printf("File open succesfully with FD : %d", fd);
    }

    close(fd);

    return 0;
}