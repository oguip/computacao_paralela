#include <stdio.h>

void multiplicarVetorPorMatriz(int vetor[], int matriz[][1000], int resultado[],
                               int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    resultado[i] =
        0; // Inicializa o elemento do resultado como zero antes de calcular

    for (int j = 0; j < colunas; j++) {
      resultado[i] +=
          vetor[j] * matriz[i][j]; // Multiplica o elemento do vetor pelo
                                   // elemento da matriz e acumula no resultado
    }
  }
}

int main() {
  int l = 1000; 
  int c = 1000;
  int vetor[1000];
  int matriz[1000][1000];
  
  for(int i = 0; i < l; i++){
    vetor[i] = i;
    for(int j = 0; j < c; j++){
      matriz[i][j] = j;
    }
  }

  int resultado[1000];

  multiplicarVetorPorMatriz(vetor, matriz, resultado, l, c);

 // printf("Resultado:\n");
 // for (int i = 0; i < l; i++) {
 //   printf("[%d] ", resultado[i]);
 // }
 // printf("\n");

  return 0;
}

