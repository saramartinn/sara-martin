#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2;
   
   
   p2 = fork();
   
   if (p2 == 0)
   {
     	printf(" Soy el hijo y el alumno es = paco\n");
   }
   else
   {
      wait(NULL);
      printf(" Soy el padre y mi PID es = %d, y el de mi hijo es = %d\n", getppid(), getpid());
   }
   exit(0);
}
