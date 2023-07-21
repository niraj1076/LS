//write a program which is used to demonstrae the concept of I/O rederiction
#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;

    scanf("%d", &iNo1);
    scanf("%d", &iNo2);

    iAns = iNo1 + iNo2;

    printf("The sum of the number is  : %d", iAns);

    return 0;
}