//write a program which creates two process as process2 and process3 and our parent process termintes till both processes terminate.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Process1 = 0, Process2 = 0, Process3 = 0;

    Process1 = fork();

    if(Process1 == 0)
    {
        Process2 = fork();
        Process3 = fork();

        if((Process2 == 0) && (Process3 == 0))
        {
            printf("Inside process2\n");
            printf("Inside process3\n");
        }
    }
    else
    {
        printf("Parent is running with PID : %d\n", getpid());
        printf("Waiting for the child process\n");
        wait(NULL);
        printf("Child process1 finished\n");
    }

    return 0;
}