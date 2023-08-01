//write a program which is used to create simple thread by using pthread library.
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *TheradProc(void *ptr)
{
  printf("Inside therad\n");
}

int main()
{
  pthread_t TID;
  int iRet = 0;

  iRet = pthread_create(&TID, NULL, TheradProc, NULL);

  if(iRet == 0)
  {
    printf("Thread created with TID : %d\n", TID);
  }
  else
  {
    printf("Unamble to create thread\n");
  }

  return 0;

}