#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
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

void fatorial(mpf_t *result, int x, mpf_t *cache) {
    if (x == 0 || x == 1) {
        mpf_set_ui(*result, 1);
    } else if (mpf_sgn(cache[x]) != 0) {
        mpf_set(*result, cache[x]);
    } else {
        fatorial(result, x - 1, cache);
        mpf_mul_ui(*result, *result, x);
        mpf_set(cache[x], *result);
    }
}


void serieTaylor(mpf_t *e, mpf_t x, int n, mpf_t *fatorial_cache) {
    mpf_t fat, fate, elocal;
    mpf_init2(fat,2097152);
    mpf_init2(fate,2097152);
    mpf_init2(elocal,2097152);
    mpf_set_ui(fat,0);
    mpf_set_ui(fate,0);
    mpf_set_ui(elocal,0);
    int local_i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    if(my_rank == 0){
        for (int i = 0; i < n; i+=2) {
            fatorial(&fat,i, fatorial_cache); //Realizo o fatorial de i e armazeno em fat
            mpf_div(fate,x,fat); //Realizo a divisao de X(1) com o fat 
            mpf_add(elocal,elocal,fate); //Adiciono em e o valor dessa divisao
        }
    }
    else{
        for (int i = 1; i <= n; i+=2) {
            fatorial(&fat,i, fatorial_cache); //Realizo o fatorial de i e armazeno em fat
            mpf_div(fate,x,fat); //Realizo a divisao de X(1) com o fat 
            mpf_add(elocal,elocal,fate); //Adiciono em e o valor dessa divisao
        }
    }
    
    #pragma omp critical
    mpf_add(*e,*e,elocal);
}


void save_to_file(mpf_t e, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    gmp_fprintf(file, "%.500000Ff\n", e);
    fclose(file);
}

int main(int argc, char *argv[]) {
    int n = 0;
    mpf_t e, x;
    mpf_init2(e, 2097152);
    mpf_init2(x, 2097152);
    mpf_set_ui(e, 0);
    mpf_set_ui(x, 1);
    int thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n", n);

    mpf_t *fatorial_cache;
    init_fatorial_cache(&fatorial_cache, n);
    serieTaylor(&e, x, n, fatorial_cache);
    clear_fatorial_cache(fatorial_cache, n);

    gmp_printf("\nResultado salvo!\n");
    save_to_file(e, "resultado.txt");
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}

