//write a program which accepts 2 file name from the user and copy the content of exesting file into ne created file.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;
    
    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Isufficent arguments \n");
        return -1;
    }

    fdSource = open(argv[1], O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }

    fdDest = creat(argv[2], 0777);
    if(fdDest == -1)
    {
        printf("Unable to create destanation file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer, sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer, 0, sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);
    return 0;
}