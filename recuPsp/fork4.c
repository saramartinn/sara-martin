#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	 pid_t pid2, pid3, pid4, pid5, pid6;
	 
	 int variable = 30;
	 pid2 = fork();
	 
	 
	 if (pid2==0)
	 {
	 	 pid5 = fork();
		 if (pid5==0)
		 {
		 	if (getpid()%2==0)
			{
				variable = variable + 100;
				printf("P5 el pid es par = %d y la variable es = %d \n", getpid(), variable);
			}
			else
			{
				variable = variable - 100;
				printf("P5 el pid es inpar = %d y la variable es = %d \n", getpid(), variable);
			}
		 }
		 else
		 {
		 	wait(NULL);
			if (getpid()%2==0)
			{
				variable = variable + 100;
				printf("P2 el pid es par = %d y la variable es = %d \n", getpid(), variable);
			}
			else
			{
				variable = variable - 100;
				printf("P2 el pid es inpar = %d y la variable es = %d \n", getpid(), variable);
			}
		 }
	 }
	 else
	 {
	 	pid3 = fork();
		 if (pid3==0)
		 {
		 	pid4 = fork();
			 if (pid4==0)
			 {
			 	if (getpid()%2==0)
				{
					variable = variable + 100;
					printf("P4 el pid es par = %d y la variable es = %d \n", getpid(), variable);
				}
				else
				{
					variable = variable - 100;
					printf("P4 el pid es inpar = %d y la variable es = %d \n", getpid(), variable);
				}
			 }
			 else //el 3
			 {
			 	wait(NULL);
			 	if (getpid()%2==0)
				{
					variable = variable + 100;
					printf("P3 el pid es par = %d y la variable es = %d \n", getpid(), variable);
				}
				else
				{
					variable = variable - 100;
					printf("P3 el pid es inpar = %d y la variable es = %d \n", getpid(), variable);
				}
			 }
		 }
		 else
		 {
			wait(NULL);
			wait(NULL);
			if (getpid()%2==0)
			{
				variable = variable + 100;
				printf("P1 el pid es par = %d y la variable es = %d \n", getpid(), variable);
			}
			else
			{
				variable = variable - 100;
				printf("P1 el pid es inpar = %d y la variable es = %d \n", getpid(), variable);
			}
		}
	 }
	 exit(0);
}
