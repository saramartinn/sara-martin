#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

void main() 
{
	int fd1[2];
	int fd2[2];
	pid_t pid, pid2;
	time_t t;

	
	int solucion, opcion, operador1, operador2;
	
	//creamos los pipes
	pipe(fd1);
	pipe(fd2);
	
	//Se crea un proceso hijo
	pid= fork();

	if (pid==0) //hijo
	{
		pid2= fork();
		if (pid2 == 0)
		{
			close(fd2[1]);
			read(fd2[0], &solucion, sizeof(solucion));
			close(fd2[0]);
			printf("Proceso P3 pid =  %d - Proceso padre pid = %d \n", getpid(), getppid());
			
			if (solucion % 2 == 0)
			{
				printf("El resultado de la operacion  %d es par \n", solucion);
			}
			else
			{
				printf("El resultado de la operacion  %d es inpar \n", solucion);
			}
		}
		else
		{
			close(fd1[1]); 
			read(fd1[0], &opcion, sizeof(opcion));
			read(fd1[0], &operador1, sizeof(operador1));
			read(fd1[0], &operador2, sizeof(operador2));
			close(fd1[0]);
			
			switch(opcion){
				case 1:
					solucion = operador1 + operador2;
					printf("Proceso P2 pid =  %d - Proceso padre pid = %d \n", getpid(), getppid());
					printf("Operacion: %d + %d = %d \n", operador1, operador2, solucion);
					break;
				case 2:
					solucion = operador1 - operador2;
					printf("Proceso P2 pid =  %d - Proceso padre pid = %d \n", getpid(), getppid());
					printf("Operacion: %d - %d = %d \n", operador1, operador2, solucion);
					break;
				case 3:
					solucion = operador1 * operador2;
					printf("Proceso P2 pid =  %d - Proceso padre pid = %d \n", getpid(), getppid());
					printf("Operacion: %d * %d = %d \n", operador1, operador2, solucion);
					break;
				case 4:
					solucion = operador1 / operador2;
					printf("Proceso P2 pid =  %d - Proceso padre pid = %d \n", getpid(), getppid());
					printf("Operacion: %d / %d = %d \n", operador1, operador2, solucion);
					break;
			}
			
			close(fd2[0]);
			write(fd2[1], &solucion, sizeof(solucion));
			close(fd2[1]);
		}
	}
	else  //padre
	{	
		
		printf("Proceso P1 pid =  %d \n", getpid());
		printf("****CALCULADORA******\n");
		printf("1. Sumar \n");
		printf("2. Restar \n");
		printf("3. Multiplicar \n");
		printf("4. Division \n");
		printf("Seleccione la opcion deseada: \n");
		scanf("%d", &opcion);
		
		printf("Introduce el operador 1: \n");
		scanf("%d", &operador1);
		
		printf("Introduce el operador 2: \n");
		scanf("%d", &operador2);
		
		close(fd1[0]);
		write(fd1[1], &opcion, sizeof(opcion));
		write(fd1[1], &operador1, sizeof(operador1));
		write(fd1[1], &operador2, sizeof(operador2));
		close(fd1[1]);
		
	}
	wait(NULL);
	exit(0);
}
