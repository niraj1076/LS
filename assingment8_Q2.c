//Write a program which create three level process hierarchy where process 1 creates process 2 and the process 2 creates the process 3.s
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Process1 = 0, Process2 = 0, Process3 = 0;

    Process1 = fork();

    if(Process1 == 0)
    {
        printf("Child of process1 => PPID %d PID : %d\n", getppid(), getpid());
        Process2 = fork();

        if(Process2 == 0)
        {
            printf("Child of process2 => PPID %d PID : %d\n", getppid(), getpid());

            Process3 = fork();
            if(Process3 == 0)
            {
                printf("Child of process3 => PPID %d PID : %d\n", getppid(), getpid());

            }
            else
            {
                printf("Parent is running with PID : %d\n", getpid());
                printf("Waiting for the child process3\n");
                wait(NULL);
                printf("Child process3 finished\n");
            }
        }
        else
        {
            printf("Parent is running with PID : %d\n", getpid());
            printf("Waiting for the child process2\n");
            wait(NULL);
            printf("Child process2 finished\n");
        }
    }
    else
    {
        printf("Parent is running with PID : %d\n", getpid());
        printf("Waiting for the child process1\n");
        wait(NULL);
        printf("Child process1 finished\n");
    }

    return 0;
}