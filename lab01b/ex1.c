#include <stdio.h>

int main() {
  int menor = 100, linha;
  int M[3][3] = {10, 4, 5, 4, 3, 7, 6, 4, 9};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(M[i][j] < menor){
        menor = M[i][j];
        linha = i+1;
      }
    }
  }
  printf("A linha onde se encontra o menor valor é: %d", linha);
  return 0;
}
