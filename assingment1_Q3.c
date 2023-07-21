//write a program which  aapet file name and one mode and to check wheather our process can access thet file in accepted maode or not 
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid numbers of arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        Mode = R_OK;        //it is the parameter of access to cheak
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        Mode = W_OK;        //it is the parameter of access to cheak
    }
    else if(strcmp(argv[2], "execute") == 0)
    {
        Mode = X_OK;        //it is the parameter of access to cheak
    }

    if(access(argv[1], Mode) < 0)
    {
        printf("Unable to acess %s file in %s mode\n", argv[1], argv[2]);
        return -1;
    }
    else
    {
        printf("File %s open succesfully with mode : %s\n",argv[1], argv[2] );
    }


    return 0;
}