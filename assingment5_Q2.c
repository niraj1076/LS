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


    printf("Enter the file name : \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDONLY);

    read(fd, &sobj, sizeof(sobj));

    printf("Roll number : %d\n", sobj.Rollno);
    printf("Name : %s\n", sobj.sName);
    printf("Marks : %f\n", sobj.Marks);
    printf("Age : %d\n", sobj.Age);
    

    return 0;
}