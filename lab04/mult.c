#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int thread_count;
int l = 1000;
int c = 1000;
int V[1000];
int M[1000][1000];
int R[1000];

void preencheMatriz() {
  for (int i = 0; i < l; i++) {
    V[i] = i;
    for (int j = 0; j < c; j++) {
      M[i][j] = j;
    }
  }
}

void printVetor(int *V, int n) {
  for (int i = 0; i < n; i++) {
    printf("[%d] ", V[i]);
  }
}

void *Pth_math_vect(void *rank) {
  long my_rank = (long)rank;
  int i, j;
  int local_l = l / thread_count;
  int my_first_row = my_rank * local_l;
  int my_last_row = (my_rank + 1) * local_l - 1;
  for (i = my_first_row; i <= my_last_row; i++) {
    R[i] = 0;
    for (j = 0; j < c; j++) {
      R[i] += M[i][j] * V[j];
      //printf("\nMultiplicado M[%d][%d] = %d por V[%d] = %d e somando em R[%d] = %d\n" ,i, j, j, i, M[i][j], V[j], R[i]);
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  preencheMatriz();
  long thread;               // Crio uma variavel do tipo long
  pthread_t *thread_handles; // Crio uma variavel do tipo pthread
  thread_count = strtol(argv[1], NULL, 10); // Determino o valor de thread_count para o retorno da função strtol
  thread_handles = malloc(thread_count * sizeof(pthread_t));
  for (thread = 0; thread < thread_count; thread++) {
    pthread_create(&thread_handles[thread], NULL, Pth_math_vect,
                   (void *)thread);
  }
  for (thread = 0; thread < thread_count; thread++) {
    pthread_join(thread_handles[thread],
                 NULL); // funcao que serve para sincronizar as threads
  }

 // printVetor(R, c);
  free(thread_handles);
  return 0;
}
