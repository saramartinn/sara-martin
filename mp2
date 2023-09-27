#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
  
  pid_t Padre, Nieto;
  
  Padre = fork();
  
  if (Padre == 0) //Nos encontramos en el padre
  {
    Nieto = fork();
    if (Nieto == 0 )  //Nos encontramos en Proceso hijo
    {        
	printf(" Soy el P3 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid()); 
    }
    else
    {
    	wait(NULL);
     	printf(" Soy el P2 y mi PID es = %d, y el de mi padre es = %d\n", getpid(), getppid()); 
    }
  }
  else  //Nos encontramos en el abuelo
  {
     wait(NULL);
     printf(" Soy el P1 y mi PID es = %d, y el de mi hijo es = %d\n", getpid(), getppid()); 
    
  }
   exit(0);
}
