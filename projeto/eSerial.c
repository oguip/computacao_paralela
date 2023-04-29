#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>


void init_fatorial_cache(mpf_t **cache, int max_n) {
    *cache = (mpf_t *)malloc((max_n + 1) * sizeof(mpf_t));
    for (int i = 0; i <= max_n; i++) {
        mpf_init((*cache)[i]);
    }
}

void clear_fatorial_cache(mpf_t *cache, int max_n) {
    for (int i = 0; i <= max_n; i++) {
        mpf_clear(cache[i]);
    }
    free(cache);
}

void next_fatorial(mpf_t *result, int x, mpf_t *cache) {
    if (x == 0 || x == 1) {
        mpf_set_ui(*result, 1);
    } else {
        mpf_set(*result, cache[x - 1]);
        mpf_mul_ui(*result, *result, x);
    }
}

void serieTaylor(mpf_t *e, mpf_t x, int n){
    mpf_t term, fate;
    mpf_init2(term,16777216);
    mpf_set_ui(term,1);
    for(int i = 0; i < n; i++){
        mpf_add(*e, *e, term); 
        mpf_mul(term,term,x);
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
    mpf_t e,x;
    mpf_init2(e,16777216);
    mpf_init2(x,16777216);
    mpf_set_ui(e,0);
    mpf_set_ui(x,1);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n",n);
    serieTaylor(&e,x,n);
    save_to_file(e, "resultadoSerial.txt");
    gmp_printf("\nResultado salvo!");
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}
