#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3, p4, suma;
   
   p2 = fork();
   
   if (p2 == 0)
   {
   	p3 = fork();
    	if (p3 == 0)
      	{
      		p4 = fork();
      		if (p4 == 0)
      		{
      			suma = getpid() + getppid();
      			printf(" Soy el P4 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      		}
      		else
      		{
      			wait(NULL);
      			suma = getpid() + getppid();
      			printf(" Soy el P3 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      		
      		}
      		
      	}
      	else
      	{
      		wait(NULL);
      		wait(NULL);
      		suma = getpid() + getppid();
      		printf(" Soy el P2 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      	}
   }
   else
   {
   	wait(NULL);
   	wait(NULL);
   	wait(NULL);
   	suma = getpid() + getppid();
   	printf(" Soy el P1 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
   
   }
   exit(0);
}

