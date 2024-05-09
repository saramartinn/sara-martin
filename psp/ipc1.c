#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	int fd[2];
	char buffer[10];
	pid_t pid;
	
	
	//creamos el pipe
	pipe(fd);
	
	//Se crea un proceso hijo
	pid= fork();

	if (pid==0)
	{
		close(fd[1]); //cierra el descriptor de lectura
		printf("Soy el hijo con PID: %d \n", getpid());
		read(fd[0], buffer, 10);
		printf("Mensaje leido del PIPE: %s \n", buffer);
		
	}
	else
	{
		close(fd[0]); //cierra el descriptor de lectura
		printf("El padre escribe en el PIPE \n");
		write(fd[1], "fecha/hora", 10);
	}
exit(0);
}
