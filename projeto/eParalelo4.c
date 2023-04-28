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

void next_fatorial(mpf_t *result, int x, mpf_t *cache) {
    if (x == 0 || x == 1) {
        mpf_set_ui(*result, 1);
    } else {
        mpf_set(*result, cache[x - 1]);
        mpf_mul_ui(*result, *result, x);
    }
}

void serieTaylor(mpf_t *e, mpf_t x, int n, mpf_t *fatorial_cache) {
    int thread_count = omp_get_max_threads();

    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int local_n = n / thread_count;
        int start = my_rank * local_n;
        int end = (my_rank + 1) * local_n - 1;
        if (my_rank == thread_count - 1) {
            end = n;
        }

        mpf_t term, elocal;
        mpf_init2(term, 8388608);
        mpf_init2(elocal, 8388608);
        mpf_set_ui(term, 1);
        mpf_set_ui(elocal, 0);

        for (int i = 0; i <= end; ++i) {
            if (i >= start) {
                mpf_add(elocal, elocal, term);
                mpf_mul(term, term, x);
                mpf_div_ui(term, term, i + 1);
            } else {
                mpf_mul(term, term, x);
                mpf_div_ui(term, term, i + 1);
            }
        }

        #pragma omp critical
        mpf_add(*e, *e, elocal);

        mpf_clear(term);
        mpf_clear(elocal);
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

int main() {
    int n = 0;
    mpf_t e, x;
    mpf_init2(e, 8388608);
    mpf_init2(x, 8388608);
    mpf_set_ui(e, 0);
    mpf_set_ui(x, 1);

    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n", n);

    mpf_t *fatorial_cache;
    init_fatorial_cache(&fatorial_cache, n);
    serieTaylor(&e, x, n, fatorial_cache);
    clear_fatorial_cache(fatorial_cache, n);

    gmp_printf("\nResultado: Salvo");
    save_to_file(e, "resultado.txt");
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}


