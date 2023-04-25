#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double f(double x){
	return exp(x);
}

void Trap(double a, double b, int n, double* global_result_p) {
  double h,x,my_result;
  double local_a, local_b;
  int i, local_n;
  int my_rank = omp_get_thread_num();
  printf("My Rank: %d\n", my_rank);
  int thread_count = omp_get_num_threads();
  h = (b-a)/n;
  local_n = n/thread_count;
  local_a = a + my_rank*local_n*h;
  local_b = local_a + local_n*h;
  my_result = (f(local_a) + f(local_b))/2.0;
  for(int i = 1; i<=local_n-1;i++){
    x = local_a + i*h;
    my_result += f(x);
  }
  my_result *= n;
  #pragma omp critial;
  *global_result_p += my_result;
}

int main(int argc, char *argv[]) {
  double global_result = 0.0;
  double a,b;
  int n;
  int thread_count;
  thread_count = strtol(argv[1], NULL, 10);
  //thread_count = 2;
  printf("Insira a, b e n: \n");
  scanf("%lf %lf %d", &a, &b, &n);
  #pragma omp parallel num_threads(thread_count)
  Trap(a,b,n,&global_result);
  printf("Com %d trapézios, nossa estimativa da integral de %f até %f = %14e\n",n,a,b,global_result);
  return 0;
}
