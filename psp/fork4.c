#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main()
{
   pid_t p2, p3, p4, p5, acumulado;
   
   p2 = fork();
   acumulado = getpid();
   
   if (p2 == 0)
   {
   	if (getpid() % 2 == 0)
   	{
   		printf(" Soy el P2, PID = %d y valor = %d \n", getpid(), (acumulado+10));
   	}
   	else
   	{
   		printf(" Soy el P2, PID = %d y valor = %d \n", getpid(), (acumulado-100));
   	}
   	
   	p5 = fork();
      	
      	if (p5 == 0)
      	{
      		if (getpid() % 2 == 0)
   		{
   			printf(" Soy el P5, PID = %d y valor = %d \n", getpid(), (acumulado+10));
   		}
   		else
   		{
   			printf(" Soy el P5, PID = %d y valor = %d \n", getpid(), (acumulado-100));
   		}
      	}
      	else //estamos en P2
      	{
      		wait(NULL);
      	}
      	
   }
   else // estamos en p1
   {
   	
      	p3 = fork();
    	if (p3 == 0)
      	{
      		if (getpid() % 2 == 0)
   		{
   			printf(" Soy el P3, PID = %d y valor = %d \n", getpid(), (acumulado+10));
   		}
   		else
   		{
   			printf(" Soy el P3, PID = %d y valor = %d \n", getpid(), (acumulado-100));
   		}
      		
      		p4 = fork();
      		if (p4 == 0)
      		{
      			if (getpid() % 2 == 0)
   			{
   				printf(" Soy el P4, PID = %d y valor = %d \n", getpid(), (acumulado+10));
   			}
   			else
   			{
   				printf(" Soy el P4, PID = %d y valor = %d \n", getpid(), (acumulado-100));
   			}
      		}
      		else //estamos en p3
      		{
      			wait(NULL);
      		}
      	}
   	wait(NULL);
   	wait(NULL);
   }
   exit(0);
}
