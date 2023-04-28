#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

void fatorial(mpf_t* result, int x) {
    mpf_init2(*result,2097152);
    mpf_set_ui(*result, 1);

    for(int i = 2; i <= x; i++) {
        mpf_t temp;
        mpf_init(temp);
        mpf_set_ui(temp, i);
        mpf_mul(*result, *result, temp);
        mpf_clear(temp);
    }
}

void serieTaylor(mpf_t *e, mpf_t x, int n, int thread_count) {
    mpf_t elocal;
    mpf_init2(elocal,2097152);
    mpf_set_ui(elocal,0);

    #pragma omp parallel num_threads(thread_count)
    {
        mpf_t fat, fate;
        mpf_init2(fat,2097152);
        mpf_init2(fate,2097152);
        mpf_set_ui(fat,0);
        mpf_set_ui(fate,0);

        int my_rank = omp_get_thread_num();
        int local_i, local_n;
        local_n = (n + 1) / thread_count * (my_rank + 1);
        local_i = (n + 1) / thread_count * my_rank;

        for (int i = local_i; i < local_n; i++) {
            fatorial(&fat, i);
            mpf_div(fate, x, fat);
            #pragma omp critical
            mpf_add(elocal, elocal, fate);
        }

        mpf_clear(fat);
        mpf_clear(fate);
    }

    mpf_set(*e, elocal);
    mpf_clear(elocal);
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
    #pragma omp parallel num_threads(thread_count)
    serieTaylor(&e, x, n, thread_count);

    gmp_printf("Resultado salvo!");
    save_to_file(e, "resultado.txt");
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}

