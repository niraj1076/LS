/*write a program which creats 2 thread by using pthread API, where one thread counts the number of capital
 charecters from demo.txt file and other thread counts number of small charecterfrom the same file */

 #include<stdio.h>
 #include<fcntl.h>
 #include<unistd.h>
#include<pthread.h>

 void ThreadProc1(void *ptr)
 {
    int iCnt = 0, iRet = 0, i = 0, fd = 0;
    char Buffer[1024];

    fd = open("Demo.txt", O_RDONLY);

    while((iRet = read(fd , Buffer, sizeof(Buffer))) != 0)
    {
      for(i = 0; i < iRet ; i++)
      {
        if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
        {
          iCnt++;
        }
      }
    }

    printf("The number of small charecter are : %d\n", iCnt);
    close(fd);
    pthread_exit(NULL);
 }

  void ThreadProc2(void *ptr)
 {
    int iCnt = 0, iRet = 0, i = 0, fd = 0;
    char Buffer[1024];

    fd = open("Demo.txt", O_RDONLY);

    while((iRet = read(fd , Buffer, sizeof(Buffer))) != 0)
    {
      for(i = 0; i < iRet ; i++)
      {
        if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
        {
          iCnt++;
        }
      }
    }

    printf("The number of Capital charecter are : %d\n", iCnt);
    close(fd);
    pthread_exit(NULL);
 }

 int main()
 {
  pthread_t TID1, TID2;
  int Ret1 = 0, Ret2 = 0;

  Ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);
  if(Ret1 == 0)
  {
    printf("Thread 1 created with TID : %d\n", TID1);
  }

  Ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);
  if(Ret2 == 0)
  {
    printf("Thread 2 created with TID : %d\n", TID2);
  }

  pthread_join(TID1, NULL);
  pthread_join(TID2, NULL);
  
  return 0;
 }