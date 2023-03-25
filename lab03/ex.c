#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
  int shmid;
  int *shm;
  int *s;

  shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  shm = shmat(shmid, NULL, 0);

  if (shm == (int*)-1) {
    perror("shmat");
    exit(1);
  }

  *shm = 1;
  printf("Valor da variável criado por pai: %d\n",*shm);

  pid_t pid = fork();
  
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) { //Processo Filho
    
    shm = shmat(shmid, NULL, 0);

    if (shm == (int*)-1) {
      perror("shmat");
      exit(1);
    }
    *shm += 2; //Filho soma 2 na mesma variável

    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }
  } else { //Processo Pai
    wait(NULL); //Espera pelo filho acabar
    
    *shm *= 4; //Pai multiplica 4 na mesma variável
    
    printf("Valor da variável agora: %d\n",*shm);
    
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }
  }
}

