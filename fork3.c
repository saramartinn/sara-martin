#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3, p4, p5, p6, abuelo1, abuelo2;
   
   printf(" Soy el P1 y mi PID es = %d y no tengo abuelo\n", getpid());
   p2 = fork();
   abuelo2 = getpid();
   
   if (p2 == 0)
   {
   	printf(" Soy el P2 y mi PID es = %d y no tengo abuelo\n", getpid());
   	
   	abuelo2 = getpid();
   	p3 = fork();
    	if (p3 == 0)
      	{
      		printf(" Soy el P3 y mi PID es = %d, y el de mi abuelo es = %d \n", getpid(), abuelo1);
      		
      		p5 = fork();
      		if (p5 == 0)
      		{
      			printf(" Soy el P5 y mi PID es = %d, y el de mi abuelo es = %d \n", getpid(), abuelo2);
      		}
      		else
      		{
      			wait(NULL);
      		}
      		
      	}
      	else // estamos en p2
      	{
      		p4 = fork();
    		if (p4 == 0)
      		{
      			printf(" Soy el P4 y mi PID es = %d, y el de mi abuelo es = %d \n", getpid(), abuelo1);
      		
      			p6 = fork();
      			if (p6 == 0)
      			{
      				printf(" Soy el P6 y mi PID es = %d, y el de mi abuelo es = %d \n", getpid(), abuelo2);
      			}
      			else
      			{
      				wait(NULL);
      			}
      		}
      		wait(NULL);
      		wait(NULL);
      		
      	}
      	
   	
   }
   else // estamos en p1
   {
   	wait(NULL);
   }
   exit(0);
}
