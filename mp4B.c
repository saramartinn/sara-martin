#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//b) la salida que genera es: CCC AAA BBB, se prodia producir una salida si el fork() tuviera mas valores

void main()
{
   printf("CCC \n");
   if (fork()!=0)
   {
      wait(NULL);
      printf("AAA \n");
   } else 
   {
      printf("BBB \n");
   }
   exit(0);
}

