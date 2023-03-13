#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **criaMatriz(int **M, int tamL, int tamC) {
  M = malloc(tamL * sizeof(int *));
  for (int i = 0; i < tamL; i++) {
    M[i] = malloc(tamC * sizeof(int *));
  }
  return M;
}

int **preencheMatriz(int **M, int tamL, int tamC) {
  int n;
  for (int i = 0; i < tamL; i++) {
    for (int j = 0; j < tamC; j++) {
      M[i][j] = rand() % 199;
    }
  }
  return M;
}

int **somaL1L2Matriz(int **M, int tamL, int tamC) {
  int *aux = (int *)malloc(tamC * sizeof(int));
  for (int i = 0; i < tamC; i++) {
    aux[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < tamC; j++) {
      aux[j] += M[i][j];
    }
  }
  for (int j = 0; j < tamC; j++) {
    M[1][j] = aux[j];
  }

  return M;
}

int **multiplicaL1L2Matriz(int **M, int tamL, int tamC) {
  int *aux = (int *)malloc(tamC * sizeof(int));
  for (int i = 0; i < tamC; i++) {
    aux[i] = 1;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < tamC; j++) {
      aux[j] *= M[i][j];
    }
  }
  for (int j = 0; j < tamC; j++) {
    M[1][j] = aux[j];
  }

  return M;
}

void printMatriz(int **M, int tamL, int tamC) {
  for (int i = 0; i < tamL; i++) {
    for (int j = 0; j < tamC; j++) {
      printf("%3d ", M[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int op;
  srand(time(0));
  int tamL = 2 + (rand() % 5);
  int tamC = 2 + (rand() % 5);
  int **M = criaMatriz(M, tamL, tamC);
  M = preencheMatriz(M, tamL, tamC);
  printf("\nMatriz original:\n");
  printMatriz(M, tamL, tamC);
  printf("\n");
  printf("Você deseja somar(1) ou multiplicar(2) as duas primeiras linhas? ");
  scanf("%d", &op);
  if (op == 1)
    M = somaL1L2Matriz(M, tamL, tamC);
  else
    M = multiplicaL1L2Matriz(M, tamL, tamC); 
  printMatriz(M, tamL, tamC);

  return 0;
}
