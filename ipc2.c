#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{

	int fd[2];
	char buffer[4];
	pid_t pid;
	int num1= 23, num2= 12, num3= 24;
	char caracter= '+';
	
	//creamos el pipe
	pipe(fd);
	
	//Se crea un proceso hijo
	pid= fork();

	if (pid==0)
	{
		close(fd[1]); //cierra el descriptor de lectura
		printf("Soy el hijo \n");
		read(fd[0], buffer, 4); 
		int suma = buffer[0] + buffer[1] + buffer[2];
		printf("Numeros a sumar: %d, %d, %d\n", buffer[0], buffer[1], buffer[2]);
		printf("Caracter: %c \n", buffer[3]);
		printf("La suma total es igual a: %d \n", suma);
	}
	else
	{
		close(fd[0]); //cierra el descriptor de lectura
		printf("El padre escribe en el PIPE \n");
		buffer[0] = num1;
		buffer[1] = num2;
		buffer[2] = num3;
		buffer[3] = caracter;
		write(fd[1], buffer, 4);
		wait(NULL);
	}
exit(0);
}
