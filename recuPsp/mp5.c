#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//b) el resultado es AAA CCC BBB, puede ser que el resultado sea tambien AAA BBB CCC ya que no hace ningun wait y podria visualizarse primero el del p1 o el del p2
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
		 if (pid2==0)
		 {
		 	printf("CCC \n");
		 }
		 else{
		 	wait(NULL);
		 	wait(NULL);
		 	printf("AAA \n");
		 }
		 
	 }
	 exit(0);
}

/*void main()
{
	 pid_t pid1, pid2;
	 printf("AAA \n");
	 pid1 = fork();
	 
	 if (pid1==0)
	 {
	 	printf("BBB \n");
	 }
	 else
	 {
		 pid2 = fork();
		 printf("CCC \n");
	 }
	 exit(0);
}*/
