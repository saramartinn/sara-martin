#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
  //b) la salida que genera es CCC/AAA/BBB
  /*printf("CCC \n");
  if (fork()!=0)
  {
 	printf("AAA \n");
  } 
  else 
  {
 	printf("BBB \n");
 	
  }*/
  //c) 
  printf("CCC \n");
  if (fork()!=0)
  {
 	printf("BBB \n");
  } 
  else 
  {
 	printf("AAA \n");
 	
  }
  exit(0);
 
}
