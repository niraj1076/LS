//wrrite a program which is udes to yield our processor by using appropriate system call
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main()
{
    int i;

    for( ;; ) {
      /* Process something... */
      for( i = 0 ; i < 1000 ; ++i )
        fun();

      /* Yield to anyone else at the same priority */
      sched_yield();
    }
    return EXIT_SUCCESS;   /* Never reached */

    return 0;
}


int fun()
{
    int i;

    for( i = 0 ; i < 10 ; ++i )
      i = i++;
      printf("%d\n", i);

    return( i );
}