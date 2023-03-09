#include <stdio.h>

int main() {
  int a;
  printf("Digite o número máximo: ");
  scanf("%d", &a);
  for(int i = 0; i < a; i++){
    a=-1;
    for(int j = 0; j < a; j++){
      printf("%d",j+1);
    }
  }
  return 0;
}
