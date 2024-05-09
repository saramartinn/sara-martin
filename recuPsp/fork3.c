#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	 pid_t pid2, pid3, pid4, pid5, pid6;
	 
	 int suma;
	 pid2 = fork();
	 
	 
	 if (pid2==0)
	 {
	 	 pid3 = fork();
		 if (pid3==0)
		 {
		 	pid5 = fork();
			 if (pid5==0)
			 {
			 	suma = getpid() + getppid();
			 	printf("P5 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
			 }
			 else //el 3
			 {
			 	wait(NULL);
			 	suma = getpid() + getppid();
			 	printf("P3 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
			 }
		 }
		 else
		 {
		 	pid4 = fork();
			 if (pid4==0)
			 {
			 	pid6 = fork();
				 if (pid6==0)
				 {
				 	suma = getpid() + getppid();
			 		printf("P6 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
				 }
				 else // el 4
				 {
				 	wait(NULL);
				 	suma = getpid() + getppid();
			 		printf("P4 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
				 }
			 }
			 else // el 2
			 {
			 	wait(NULL);
			 	wait(NULL);
			 	suma = getpid() + getppid();
			 	printf("P2 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
			 }
		 }
	 }
	 else
	 {
		wait(NULL);
		suma = getpid() + getppid();
		printf("P1 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
	 }
	 exit(0);
}
