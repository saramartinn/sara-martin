#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
	int fd1[2];
	int fd2[2];
	char buffer1[1];
	char buffer2[1];
	pid_t pid;
	
	int num;
	int factorial = 1;
	
	//creamos los pipes
	pipe(fd1);
	pipe(fd2);
	
	//Se crea un proceso hijo
	pid= fork();

	if (pid==0) //hijo
	{
		close(fd1[1]); 
		read(fd1[0], buffer1, 1);
		printf("Soy el hijo, el numero aleatorio es: %d \n", buffer1[0]);
		for (int i = 1; i <= buffer1[0] ; i++)
		{
			factorial = factorial *i;
		}
		close(fd2[0]);
		printf(" %d \n", factorial);
		buffer2[0] = factorial;
		write(fd2[1], buffer2, 1);
	}
	else  //padre
	{	
		close(fd1[0]); 
		num = 7;
		buffer1[0] = num;
		write(fd1[1], buffer1, 1);
		
		close(fd2[1]);
		read(fd2[0], buffer2, 1);
		printf("Soy el padre, el factorial es: %d \n", buffer2[0]);
	}
exit(0);
}
