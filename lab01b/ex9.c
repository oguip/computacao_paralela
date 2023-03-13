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
      M[i][j] = (rand() % 199) - 99;
    }
  }
  return M;
}

int **moduloMatriz(int **M, int tamL, int tamC) {
  for (int i = 0; i < tamL; i++) {
    for (int j = 0; j < tamC; j++) {
      if (M[i][j] < 0)
        M[i][j] = abs(M[i][j]);
    }
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
  srand(time(0));
  int tamL = rand() % 10;
  int tamC = rand() % 10;
  int **M = criaMatriz(M, tamL, tamC);
  M = preencheMatriz(M, tamL, tamC);
  printf("\nMatriz original:\n");
  printMatriz(M, tamL, tamC);
  int **MM = moduloMatriz(M, tamL, tamC);
  printf("\nMesma matriz só positiva:\n");
  printMatriz(MM, tamL, tamC);
  return 0;
}
