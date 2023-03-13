#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char nome[50];
  int idade, peso, altura;
} Pessoa;

int main() {
  Pessoa p1, p2, p3;
  Pessoa VP[3] = {p1, p2, p3};
  srand(time(0));
  printf("Digite os nomes:\n");
  for (int i = 0; i < 3; i++) {
    fgets(VP[i].nome, 50, stdin);
    VP[i].idade = 10 + (rand() % 80);
    VP[i].peso = 50+(rand() % 90);
    VP[i].altura = 150 + (rand() % 33);
  }
  for (int i = 0; i < 3; i++) {
    printf("Nome:%sIdade:%d\nPeso:%d\nAltura:%d\n\n",VP[i].nome,VP[i].idade,VP[i].peso,VP[i].altura);
  }
  return 0;
}
