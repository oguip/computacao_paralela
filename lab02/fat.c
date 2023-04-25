#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int pai(int j, int i) {
  int aux = j;
  for (i = 1; j > aux/2; j--) {
    i = i * j;
  }
  //printf("\nVALOR PAI: %d\n",i);
  return i;
}

int filho(int j, int i) {
  j /= 2;
  for (i = 1; j > 1; j--) {
    i = i * j;
  }
  //printf("\nVALOR FILHO: %d\n",i);
  return i;
}



int main(){
  int i = 0;
  int num, j, v2, v3;
  int pip1[2];
  pid_t pid;

  if(pipe(pip1)<0) {
      perror("pipe") ;
      return -1 ;
  }

  //printf("Enter the number: ");
  //scanf("%d", &num);
  num= 10;
  j = num;
  pid = fork();

  if(pid == -1){ perror("fork"); return -1; }

  if(pid > 0) {
    close(pip1[0]);
    int v1 = pai(j, i);
    write(pip1[1], &v1,sizeof(v1));
    exit(0);
  }
  else{
    close(pip1[1]);
    int v2;
    int v3 = filho(j,i);
    read(pip1[0],&v2,sizeof(v2));
    printf("The factorial of %d is %d\n", num, v3*v2);
    exit(0);
  }
  return 0;
  }

