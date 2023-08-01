//write a program which creats two thread, first thread prints from 1 to 500 and the second thread print from 500 to 1
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *TheradProc1(void *ptr)
{
  int iCnt = 0;
  for(iCnt = 0; iCnt <= 500; iCnt++)
  {
    printf("Thread1 counter : %d\n", iCnt);
  }
}

void *TheradProc2(void *ptr)
{
  int iCnt = 0;
  for(iCnt = 500; iCnt >= 0; iCnt--)
  {
    printf("Thread2 counter : %d\n", iCnt);
  }
}


int main()
{
  pthread_t TID1,TID2;
  int iRet = 0;

  iRet = pthread_create(&TID1, NULL, TheradProc1, NULL);

  if(iRet == 0)
  {
    printf("Thread created with TID : %d\n", TID1);
  }
  else
  {
    printf("Unable to create thread\n");
  }


  iRet = pthread_create(&TID2, NULL, TheradProc2, NULL);

  if(iRet == 0)
  {
    printf("Thread created with TID : %d\n", TID2);
  }
  else
  {
    printf("Unable to create thread\n");
  }


  pthread_join(TID1, NULL);
  pthread_join(TID2, NULL);


  return 0;

}