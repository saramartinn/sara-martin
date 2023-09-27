#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
  
  pid_t hijo, pid_hijo, pid_padre;
  
  hijo = fork();
  pid_hijo = getpid();
  pid_padre = getppid();
  
  if (hijo == 0) 
  {
    printf("Hola soy Sara \n ");
  }
  else
  {
     wait(NULL);
     printf("El pid del hijo es= %d y el del padre es= %d\n ", pid_hijo, pid_padre);
    
  }
   exit(0);
}
