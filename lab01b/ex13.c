#include <stdio.h>
#include <stdlib.h>

int main() {
  int remover = 18;
  char Str[100] = "REMOVER ESSA AQUI O REMOVEU";
  printf("\nA Str armazenado foi: %s, vai remover o char %d\n", Str, remover);
  int i;
  int flag = 0;
  for (i=0; i<100; i++)
  {
    if (i == remover){
      flag = 1;
    }
    if (flag == 1)
    {
      Str[i] = Str[i-1];
    }
  }

  printf("\nA nova Str armazenada foi: %s", Str);
  return 0;
}
