#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3, p4;
   
   p2 = fork();
   
   if (p2 == 0)
   {
     	if ((getpid() % 2) == 0)
     	{
     		printf(" Soy el P2 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     	}
     	else
     	{
     		printf(" Soy el P2 y mi PID es = %d \n", getpid());
     	}
   }
   else
   {
      p3 = fork();
      wait(NULL);
      if (p3 == 0)
      {
      	p4 = fork();
      	if (p4 == 0){
      		if ((getpid() % 2) == 0)
      		{
     			printf(" Soy el P4 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     		}	
     		else
     		{
     			printf(" Soy el P4 y mi PID es = %d \n", getpid());
     		}
      	}
      	else
      	{
      		wait(NULL);
      		if ((getpid() % 2) == 0)
      		{
     			printf(" Soy el P3 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     		}
     		else
     		{
     			printf(" Soy el P3 y mi PID es = %d \n", getpid());
     		}
      	}
      }
      else
      {
      	wait(NULL);
      	wait(NULL);
      	
      	if ((getpid() % 2) == 0)
      	{
     		printf(" Soy el P1 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
     	}
     	else
     	{
     		printf(" Soy el P1 y mi PID es = %d \n", getpid());
     	}
      	
      }
   }
   exit(0);
}

