#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//a) el orden de los procesos puede ser o primero el p2, luego p4, p3 y p1 o p4, p3, p2, p1 o p4, p2, p3, p1 siempre tiene q ser el ultimo p1 y p4 siempre tiene q ir antes q p3. 
void main()
{
	 pid_t pid2, pid3, pid4;
	 
	 pid2 = fork();
	 
	 if (pid2==0)
	 {
	 	if (getpid()%2==0)
		{
			printf("P2 el pid es par = %d y el de mi padre = %d \n", getpid(), getppid());
		}
		else
		{
			printf("P2 pid es impar = %d \n", getpid());
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
			 		printf("P4 el pid es par = %d y el de mi padre = %d \n", getpid(), getppid());
			 	}
			 	else
			 	{
			 		printf("P4 pid es impar = %d \n", getpid());
			 	}
			 }
			 else{
			 	wait(NULL);
			 	if (getpid()%2==0)
			 	{
			 		printf("P3 el pid es par = %d y el de mi padre = %d \n", getpid(), getppid());
			 	}
			 	else
			 	{
			 		printf("P3 pid es impar = %d \n", getpid());
			 	}
			 }
		 }
		 else{
		 	wait(NULL);
		 	wait(NULL);
		 	if (getpid()%2==0)
			{
			 	printf("P1 el pid es par = %d y no tiene padre \n", getpid());
			}
			else
			{
			 	printf("P1 pid es impar = %d \n", getpid());
			}
		 }
		 
	 }
	 exit(0);
}
