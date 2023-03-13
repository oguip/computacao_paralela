#include <stdio.h>
#include <stdlib.h>

int main() {
  char n1[100];
  char n2[100];
  int i = 0;
  printf("Digite o primeiro nome: ");
  fgets(n1, 100, stdin);
  printf("Digite o segundo nome: ");
  fgets(n2, 100, stdin);
  while (n1[i] != '\0' && n2[i] != '\0') {
    if (n1[i] < n2[i]) {
      printf("%s\n%s", n1, n2);
      break;
    } if (n2[i] < n1[i]) {
      printf("%s\n%s", n2, n1);
      break;
    } else i++;
    
  }
  printf("\n");
  return 0;
}
