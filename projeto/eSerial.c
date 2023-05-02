#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

void serieTaylor(mpf_t *e, int n){
    mpf_t term, fate;
    mpf_init2(term,16777216);
    mpf_set_ui(term,1);
    for(int i = 0; i < n; i++){
        mpf_add(*e, *e, term); 
        mpf_div_ui(term,term,i+1);
    }
}


void save_to_file(mpf_t e, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    gmp_fprintf(file, "%.3000000Ff\n", e);
    fclose(file);
}

int main(void) {
    int n = 0;
    mpf_t e;
    mpf_init2(e,16777216);
    mpf_set_ui(e,0);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n",n);
    serieTaylor(&e, n);
    save_to_file(e, "resultadoSerial.txt");
    gmp_printf("\nResultado salvo!");
    mpf_clear(e);
    return 0;
}
