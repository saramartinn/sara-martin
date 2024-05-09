#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3, p4, suma;
   
   suma = getpid() + getppid();
   printf(" Soy el P1 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
   p2 = fork();
   
   if (p2 == 0)
   {
   	
      	suma = getpid() + getppid();
      	printf(" Soy el P2 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      	
   	p3 = fork();
    	if (p3 == 0)
      	{
      		suma = getpid() + getppid();
      		printf(" Soy el P3 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      		
      		p4 = fork();
      		if (p4 == 0)
      		{
      			suma = getpid() + getppid();
      			printf(" Soy el P4 y mi PID es = %d, y el del padre es = %d, la suma = %d\n", getpid(), getppid(), suma);
      		}
      		else //estamos en p3
      		{
      			wait(NULL);
      		}
      		
      	}
      	else //estamos en p2
      	{
      		wait(NULL);
      	}
   }
   else //estamos en p1
   {
   	wait(NULL);
   }
   exit(0);
}

