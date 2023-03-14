#include <stdio.h>
#include <stdlib.h>

int main() {
  int inserir = 7;
  char Str[100] = "INSERIR AQUI NA POSICAO 7";
  char charInserir = 'A';
  printf("\nA Str armazenado foi: %s, vai inserir o char %c na posicao: %d\n", Str, charInserir, inserir);
  int i;
  for (i=0; i<100; i++)
  {
    if (i == inserir){
      Str[i] = charInserir;
    }
  }

  printf("\nA nova Str armazenada foi: %s", Str);
  return 0;
}
