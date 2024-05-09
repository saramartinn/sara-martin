#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
  
  pid_t p2, p3;
  
  p2 = fork();
  
  if (p2 == 0 ) 
  {
    printf("Me voy a dormir\n ");
    sleep(10);
    printf("Despierto \n ");
  }
  else{
  p3 = fork();
  
	  if (p3 == 0)
	   {
	      printf(" Soy el P3 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid());
	  }else{
	     wait(NULL);
	     wait(NULL);
	     printf("Soy el padre\n ");
	  }
  }
  exit(0);
}
