//write a program which create single thread and we pass a parameter to that thread from main thread;
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *TheradProc(void *ptr)
{
  printf("The value sent is : %d\n", ptr);

}

int main()
{
  pthread_t TID1,TID2;
  int iRet = 0, Value = 0;

  printf("Enter the value to send : \n");
  scanf("%d", &Value);

  iRet = pthread_create(&TID1, NULL, TheradProc, (int *)Value);

  if(iRet == 0)
  {
    printf("Thread created with TID : %d\n", TID1);
  }
  else
  {
    printf("Unable to create thread\n");
  }

  pthread_join(TID1, NULL);

  return 0;

}