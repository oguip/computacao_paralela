#include <stdio.h>
#include <math.h>

long double serieTaylor(int x, int n){
  long double e;
  for(int i = 0; i < n; i++){
    e += x/tgamma(i);
  }
  return e;
}


int main(void) {
  int x = 1;
  int n;
  printf("Insira o n: ");
  scanf("%d", &n);
  printf("\nResultado: %.100Lf\n",serieTaylor(x,n));
  return 0;
}
