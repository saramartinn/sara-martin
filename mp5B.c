#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//la salida que genera es: AAA CCC BBB CCC, si se podria producir si el fork() diera otros valores

void main()
{
   pid_t pid1, pid2;
   printf("AAA \n");
   pid1 = fork();
   
   if (pid1==0)
   {
      printf("BBB \n");
   }
   else
   {
      pid2 = fork();
      printf("CCC \n");
   }
   exit(0);
}

