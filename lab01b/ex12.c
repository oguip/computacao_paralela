#include <stdio.h>

int buscar(char *str, char letra) {
    char *temp = str;
    while (*temp != 0 && *temp != letra)
        temp++;
    return temp - str;
}

int main() {
    char *str = "Gabriel";
    int letra = 'e';
    int posicao = buscar(str, letra);
    printf("%d\n", posicao+1);
}
