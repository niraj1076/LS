//write a program which creats three diffrent process internally as process2, process3 and process4. 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Process1 = 0, Process2 = 0, Process3 = 0, Process4 = 0;

    Process1 = fork();

    if(Process1 == 0)
    {
        Process2 = fork();
        Process3 = fork();
        Process4 = fork();

        if((Process2 == 0) && (Process3 == 0) && (Process4 == 0))
        {
            printf("child process2 :  %d\n", getpid());
            printf("child process4 :  %d\n", getpid());
            printf(" child process3 :  %d\n", getpid());
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