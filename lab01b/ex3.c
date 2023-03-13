#include <stdio.h>

int main() {
    int n;
    printf("Número ímpar: ");
    scanf("%d", &n);

    int espacos = 0;
    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < espacos; j++) {
            printf("  ");
        }
        espacos++;
        for (int j = i; j <= n; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}

