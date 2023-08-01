//write a program which create single thread and we pass a parameter to that thread from main thread and also return some alue to caller(main thread) thread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *TheradProc(void *ptr)
{
  int i = (int)ptr;
  printf("Value recived is : %d\n", i);
  int doubleNo = 0;

  doubleNo = i + i;
  pthread_exit(doubleNo);
}

int main()
{
  pthread_t TID;
  int iRet = 0, Value = 0, Ans = 0 ;


  printf("Enter the first to send : \n");
  scanf("%d", &Value);

  iRet = pthread_create(&TID, NULL, TheradProc, (int *)Value);

  if(iRet == 0)
  {
    printf("Thread created with TID : %d\n", TID);
  }
  else
  {
    printf("Unable to create thread\n");
  }
  pthread_join(TID, &Ans);

  printf("The Double of that numbers is : %d\n",Ans );


  return 0;

}