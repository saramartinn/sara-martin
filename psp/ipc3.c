#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	int fd[2];
	char buffer[2];
	pid_t pid;
	int num1= 23, num2= 12, num3= 24;
	char caracter= '+';
	
	//creamos el pipe
	pipe(fd);
	
	//Se crea un proceso hijo
	pid= fork();

	if (pid==0)
	{
		close(fd[0]); //cierra el descriptor de lectura
		printf("El hijo escribe en el PIPE \n");
		num1 = rand() % 50 + 1;
    		num2 = rand() % 50 + 1;
		buffer[0] = num1;
		buffer[1] = num2;
		write(fd[1], buffer, 2);
		
	}
	else
	{
		close(fd[1]); //cierra el descriptor de lectura
		printf("Soy el padre\n");
		read(fd[0], buffer, 2); 
		int suma = buffer[0] + buffer[1] ;
		int resta = buffer[0] - buffer[1] ;
		int multiplicacion = buffer[0] * buffer[1] ;
		int division = buffer[0] / buffer[1] ;
		printf("%d + %d = %d\n", buffer[0], buffer[1], suma);
		printf("%d - %d = %d\n", buffer[0], buffer[1], resta);
		printf("%d * %d = %d\n", buffer[0], buffer[1], multiplicacion);
		printf("%d / %d = %d\n", buffer[0], buffer[1], division);
		wait(NULL);
	}
exit(0);
}
