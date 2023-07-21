//write a program which writes structure in file. Structure should contain information of student.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct student
{
    int Rollno;
    char sName[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct student sobj;
    char Fname[30];
    int fd = 0;

    sobj.Rollno = 11;
    sobj.Marks = 89.90;
    sobj.Age = 22;
    strcpy(sobj.sName, "raj");

    printf("Enter the file name : \n");
    scanf("%s", Fname);

    fd = creat(Fname, 0777);

    write(fd, &sobj, sizeof(sobj));

    return 0;
}