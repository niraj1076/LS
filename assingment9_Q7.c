//write a program which is used to bring home dorectory, and login user name;
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>

const char *homedir;

int main()
{
  if((homedir = getenv("HOME")) == NULL)
  {
    homedir = getpwuid(getuid()) -> pw_dir;
  }

  printf("Home directory and login user name : %s\n", homedir);
  

  return 0;
}