#include <stdio.h>
#include <stdlib.h>

int main() {
  char *n1 = (char *)malloc(sizeof(char));
  char *n2 = (char *)malloc(sizeof(char));
  int i = 0;
  printf("Digite o primeiro nome: ");
  gets(n1);
  printf("Digite o segundo nome: ");
  gets(n2);
  while (n1[i] != '\0' && n2[i] != '\0') {
    if (n1[i] < n2[i]) {
      printf("%s\n%s", n1, n2);
      i++;
      break;
    } else {
      printf("%s\n%s", n2, n1);
      i++;
      break;
    }
    i++;
  }
  printf("\n");
  free(n1);
  free(n2);
  return 0;
}
