//write a program which writes structure in file. Structure should contain information of student.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>

#pragma pack(1)
struct Regular
{
    char Fname[30];
    int Ftype;
    int InodeNo;
    int NumberLinks;
};

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct Regular robj;
    char DirName[30];
    char name[30];
    int fd = 0;

    printf("Enter name if directory\n");
    scanf("%s", DirName);
    
    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Hello.txt", 0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", DirName, entry -> d_name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            strcpy(robj.Fname, entry->d_name);
            robj.Ftype = entry -> d_type;
            robj.InodeNo = entry -> d_ino;
            write(fd, &robj, sizeof(robj));

            printf("name : %s | file type : %d | Inode no : %d\n", robj.Fname, robj.Ftype, robj.InodeNo);
        }
    }

    closedir(dp);
    close(fd);


    return 0;
}