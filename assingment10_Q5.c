//write a program which is used ti get thread id inside its thread function.
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *TheradProc(void *ptr)
{
  
  printf("Its the TID is fetched from inside thread: %d\n", pthread_self());
}

int main()
{
  pthread_t TID;
  int iRet = 0;

  iRet = pthread_create(&TID, NULL, TheradProc,NULL);

  if(iRet == 0)
  {
    printf("Thread created with TID from main : %d\n", TID);
  }
  else
  {
    printf("Unable to create thread\n");
  }
  pthread_join(TID, NULL);


  return 0;

}