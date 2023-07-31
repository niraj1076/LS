//write a program which is use to inscrease the prority by 5.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>

int main()
{
    int Process = 0, Ret = 0;

    Process = fork();

    if(Process == 0)
    {
        Process = nice(5);

        Ret = getpriority(PRIO_PROCESS, 0);

        printf("Priority of process: %d\n",Ret);
    }

    return 0;
}