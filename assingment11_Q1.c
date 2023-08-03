#include<stdio.h>
#include<pthread.h>

void ThreadProc1(void *ptr)
{
  printf("Insdide thread 1 with TID : %d\n", pthread_self());
  pthread_exit(NULL);

}

void ThreadProc2(void *ptr)
{
  printf("Insdide thread 2 with TID : %d\n", pthread_self());
  pthread_exit(NULL);
}

void ThreadProc3(void *ptr)
{
  printf("Insdide thread 3 with TID : %d\n", pthread_self());
  pthread_exit(NULL);
}

void ThreadProc4(void *ptr)
{
  printf("Insdide thread 4 with TID : %d\n", pthread_self());
  pthread_exit(NULL);
}


int main()
{
  pthread_t TID1, TID2, TID3, TID4;
  int iRet1 = 0, iRet2 = 0, iRet3 = 0,iRet4 = 0;

  iRet1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);
  if(iRet1 == 0)
  {
    printf("Inside thread 1\n");
  }


  iRet2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);
  if(iRet2 == 0)
  {
    printf("Inside thread 2\n");
  }


  iRet3 = pthread_create(&TID3, NULL, ThreadProc3, NULL);
  if(iRet3 == 0)
  {
    printf("Inside thread 3\n");
  }


  iRet4 = pthread_create(&TID4, NULL, ThreadProc4, NULL);
  if(iRet4 == 0)
  {
    printf("Inside thread 4\n");
  }

  pthread_join(TID1, NULL);
  pthread_join(TID2, NULL);
  pthread_join(TID3, NULL);
  pthread_join(TID4, NULL);

  printf("End of main \n");

  pthread_exit(NULL);

  return 0;
}