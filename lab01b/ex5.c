#include <stdio.h>
#include <stdlib.h>

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
      printf("\nColuna: %d Linha: %d // Valor: ", i, j);
      scanf("%d", &n);
      M[i][j] = n;
    }
  }
  return M;
}

int **multL(int **M, int tamL, int tamC) {
  int linha, n;
  printf("Qual linha deseja multiplicar? Sendo 1 a primeira:  ");
  scanf("%d", &linha);
  printf("E por qual número? ");
  scanf("%d", &n);
  for (int i = 0; i < tamC; i++) {
    M[linha - 1][i] *= n;
  }
  return M;
}

int **multC(int **M, int tamL, int tamC) {
  int coluna, n;
  printf("Qual coluna deseja multiplicar? Sendo 1 a primeira:  ");
  scanf("%d", &coluna);
  printf("E por qual número? ");
  scanf("%d", &n);
  for (int i = 0; i < tamL; i++) {
    M[i][coluna - 1] *= n;
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
  int tamL, tamC, op;
  printf("Qual o numero de linhas? ");
  scanf("%d", &tamL);
  printf("\nQual o numero de colunas? ");
  scanf("%d", &tamC);
  int **M = criaMatriz(M, tamL, tamC);
  M = preencheMatriz(M, tamL, tamC);
  printf("\nMatriz original:\n");
  printMatriz(M, tamL, tamC);
  printf("\n");
  printf("Você deseja multiplicar uma linha(1) ou uma coluna(2)? ");
  scanf("%d", &op);
  if (op == 1)
    multL(M, tamL, tamC);
  else
    multC(M, tamC, tamL);
  printf("Matriz alterada: ");
  printf("\n");
  printMatriz(M, tamL, tamC);
  return 0;
}
