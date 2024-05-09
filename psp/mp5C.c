#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
   pid_t pid1, pid2;
   
   pid1 = fork();
   
   if (pid1==0)
   {
 	printf("BBB \n");
   }
   else
   {
   	
	pid2 = fork();
	wait(NULL);
	
   	if(pid2 == 0){
		 printf("CCC \n");
		 wait(NULL);
	 }
	 else{
		 wait(NULL);
		 wait(NULL);
		 printf("AAA \n");
	 }
   }
   exit(0);
}

