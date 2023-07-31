//write a program in which parent process waits till its child process terminates 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)            //child
    {
        execl("./ChildProcess", "NULL", NULL);
    }
    else            //parent
    {
        printf("Parent is running with PID : %d\n", getpid());
        cpid = wait(&Exit_status);
        printf("Child process terminted have PID %d with exit status %d\n", cpid, Exit_status);
    }


    return 0;
}