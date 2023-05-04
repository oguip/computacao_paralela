#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>


void fatorial(mpf_t resultado, int n, int thread_count){
    mpf_set_ui(resultado, 1);
    
    if (n <= 1) {
        return;
    }

    mpf_t *partial_results = malloc(thread_count * sizeof(mpf_t));
    for (int i = 0; i < thread_count; ++i) {
        mpf_init_set_ui(partial_results[i], 1);
    }

    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int local_n = n / thread_count;
        int start = my_rank * local_n + 1;
        int end = (my_rank + 1) * local_n;

        if (my_rank == thread_count - 1) {
            end = n;
        }

        for (int i = start; i <= end; i++) {
            mpf_mul_ui(partial_results[my_rank], partial_results[my_rank], i);
        }
    }

    for (int i = 0; i < thread_count; ++i) {
        mpf_mul(resultado, resultado, partial_results[i]);
        mpf_clear(partial_results[i]);
    }

    free(partial_results);
}

void serieTaylor(mpf_t e, int n, int thread_count) {
    printf("\nQuantiade de threads: %d\n",thread_count);

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
        mpf_init2(term, 16777216);
        mpf_init2(elocal, 16777216);
        mpf_set_ui(term, 1);
        mpf_set_ui(elocal, 0);

        for (int i = 0; i <= end; ++i) {
            if (i >= start) {
                mpf_add(elocal, elocal, term);
                mpf_div_ui(term, term, i + 1);
            } else {
                fatorial(term,start,thread_count);
                mpf_ui_div(term,1,term);
                i = start;
            }
        }

        #pragma omp critical
        mpf_add(e, e, elocal);

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

int main(int argc, char *argv[]) {
    int n = 0;
    mpf_t e;;
    mpf_init2(e, 16777216);
    mpf_set_ui(e, 0);
    int thread_count = strtol(argv[1], NULL, 10);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n", n);

    serieTaylor(e, n, thread_count);
    gmp_printf("\nPrévia do resultado: %.15Ff",e);
    gmp_printf("\nResultado: Salvo");
    save_to_file(e, "resultadoParalelo.txt");
    mpf_clear(e);
    return 0;
}
