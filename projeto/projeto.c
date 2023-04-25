#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void serieTaylor(int x, int n, double *global_e) {
  double e = 0;
  int local_i, local_n;
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  local_n = (n + 1 / thread_count);
  printf("MY RANK:%d\n",my_rank);
  printf("thread_count:%d\n",thread_count);  
  // talvez isso funcione, o problema vai ser com o my_rank = 0;
  local_n = (n+1)/thread_count * (my_rank+1);
  local_i = (n+1)/thread_count * my_rank;
  printf("\nlocal_i: %d local_n: %d\n", local_i, local_n);
  for (int i = local_i; i < local_n; i++) {
    e += x / tgamma(i);
    printf("Valor que e recebe: %lf\n",e);
  }
  #pragma omp critical
  *global_e += e;
}

int main(int argc, char *argv[]) {
  int x = 1;
  int n = 0;
  double global_e = 0;
  int thread_count;
  thread_count = strtol(argv[1], NULL, 10);
  printf("Insira o n: ");
  scanf("%d", &n);
  #pragma omp parallel num_threads(thread_count)
  serieTaylor(x, n, &global_e);
  printf("\nResultado: %.100lf\n", global_e);
  return 0;
}
