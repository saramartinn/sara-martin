#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//a) el orden de los procesos puede ser o primero el p2, luego p4, p3 y p1 o p4, p3, p2, p1 o p4, p2, p3, p1 siempre tiene q ser el ultimo p1 y p4 siempre tiene q ir antes q p3. 
void main()
{
	 pid_t pid2, pid3, pid4;
	 
	 int suma;
	 pid2 = fork();
	 
	 if (pid2==0)
	 {
	 	pid3 = fork();
		 if (pid3==0)
		 {
		 	pid4 = fork();
			 if (pid4==0)
			 {
			 	suma = getpid() + getppid();
			 	printf("P4 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
			 }
			 else{
			 	wait(NULL);
			 	suma = getpid() + getppid();
			 	printf("P3 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
			 }
		 }
		 else
		 {
		 	wait(NULL);
		 	suma = getpid() + getppid();
			printf("P2 pid = %d , el del padre = %d y la suma %d \n", getpid(), getppid(), suma);
		 }
	 }
	 else
	 {	
		wait(NULL);
		printf("P1 pid = %d , no tiene padre y la suma es %d \n", getpid(), getpid());
		 
	 }
	 exit(0);
}
