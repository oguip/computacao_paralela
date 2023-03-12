#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamL;
  int tamC;
  printf("Qual o numero de linhas? ");
  scanf("%d", &tamL);
  printf("\nQual o numero de colunas? ");
  scanf("%d", &tamC);
  int l, c, mat[tamL][tamC], trans[tamC][tamL];


  for(l = 0; l < tamL; l++){
      for(c = 0; c < tamC; c++){
          int N = 0;
          printf("\nColuna: %d Linha: %d // Valor: ", c, l);
          scanf("%d", &N);
          mat[l][c] = N;
      }
  }

  printf("\nMatriz original:\n");
  for(l = 0; l < tamL; l++){
      for(c = 0; c < tamC; c++){
          printf("%3d ", mat[l][c]);
      }
      printf("\n");
  }

  for(l = 0; l < tamL; l++){
      for(c = 0; c < tamC; c++){
          trans[c][l] = mat[l][c];
      }
  }

  printf("\nMatriz transposta:\n");
  for(l = 0; l < tamC; l++){
      for(c = 0; c < tamL; c++){
          printf("%3d ", trans[l][c]);
      }
      printf("\n");
  }

  return 0;
}
