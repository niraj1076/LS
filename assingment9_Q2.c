#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Process1 = 0, Process2 = 0;

    int fdW = 0;
    char BufferW[1024] = {'\0'};

    fdW = open("count.txt", O_WRONLY);

    Process1 = fork();

    if(Process1 == 0)
    {
        char Buffer[512] = {'\0'};
        int iCnt = 0, fd = 0, i = 0, Ret = 0;

        fd = open("Demo.txt", O_RDONLY);

        while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
        {
            for(i = 0; i < Ret; i++)
            {
                if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
                {
                    iCnt++;
                }
            }
        }
        write(fdW,(char *) Ret, sizeof(Ret));
        close(fd);
        exit(0);
    }

    Process2 = fork();

    if(Process2 == 0)
    {
        char Buffer[512];
        int iCnt = 0, fd = 0, i = 0, Ret = 0;

        fd = open("Hello.txt", O_RDONLY);

        while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
        {
            for(i = 0; i < Ret; i++)
            {
                if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
                {
                    iCnt++;
                }
            }
        }
        printf("The number of Capital charecter are : %d\n", iCnt);
        close(fd);
        exit(0);
    }


    

    return 0;
}