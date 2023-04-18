#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	return exp(x);
}

void Trap(double a, double b, int n, double *approx) {
  double x_i,h;
  *approx = (f(a) + f(b))/2.0;
  h = (b-a)/n;
  for(int i = 1; i<=n-1;i++){
    x_i = a + i*h;
    *approx += f(x_i);
  }
  *approx *= h;
}

int main(void) {
  double approx = 0.0;
  double a,b;
  int n;
  printf("Insira a, b e n: \n");
  scanf("%lf %lf %d", &a, &b, &n);
  Trap(a,b,n,&approx);
  printf("Com %d trapézios, nossa estimativa da integral de %f até %f = %14e\n",n,a,b,approx);
  return 0;
}
