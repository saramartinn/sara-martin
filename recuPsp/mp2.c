#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3;
   
   
   p2 = fork();
   
   if (p2 == 0)
   {
     	p3 = fork();
     	if (p3 == 0)
     	{
     		printf("Soy el P3 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     	}
     	else
     	{
     		wait(NULL);
     		printf("Soy el P2 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     	}
   }
   else
   {
      wait(NULL);
      printf("Soy el P1 y mi PID es = %d, y el de mi hijo es = %d\n", getppid(), getpid());
   }
   exit(0);
}
