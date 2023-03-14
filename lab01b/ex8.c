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

int **criaMatrizTransposta(int **M, int tamL, int tamC) {
  M = malloc(tamC * sizeof(int *));
  for (int i = 0; i < tamC; i++) {
    M[i] = malloc(tamL * sizeof(int *));
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

int **preencheTransposta(int **M, int **Transposta, int tamL, int tamC) {
  for (int i = 0; i < tamL; i++) {
    for (int j = 0; j < tamC; j++) {
      Transposta[j][i] = M[i][j];
    }
  }
  return Transposta;
}

void printMatriz(int **M, int tamL, int tamC) {
  for (int i = 0; i < tamL; i++) {
    for (int j = 0; j < tamC; j++) {
      printf("%3d ", M[i][j]);
    }
    printf("\n");
  }
}

void printMatrizTransposta(int **M, int tamL, int tamC) {
  for (int i = 0; i < tamC; i++) {
    for (int j = 0; j < tamL; j++) {
      printf("%3d ", M[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(0));
  int tamL = 2 + (rand() % 5);
  int tamC = 2 + (rand() % 5);
  int **M = criaMatriz(M, tamL, tamC);
  int **Transposta = criaMatrizTransposta(Transposta, tamL, tamC);
  M = preencheMatriz(M, tamL, tamC);
  Transposta = preencheTransposta(M, Transposta, tamL, tamC);
  printf("\nMatriz original:\n");
  printMatriz(M, tamL, tamC);
  printf("\nAgora Transposta\n");
  printMatrizTransposta(Transposta, tamL, tamC);

  return 0;
}
