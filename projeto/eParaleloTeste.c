#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

void partial_sum(mpf_t result, int start, int end, int step) {
    mpf_t term, inv_term;
    mpf_init2(term, 16777216);
    mpf_init2(inv_term, 16777216);
    mpf_set_ui(term, 1);
    mpf_set_ui(result, 0);

    for (int i = start; i <= end; i += step) {
        mpf_ui_div(inv_term, 1, term);
        mpf_add(result, result, inv_term);
        for (int j = 0; j < step; ++j) {
            mpf_div_ui(term, term, i + j + 1);
        }
    }

    mpf_clear(term);
    mpf_clear(inv_term);
}

void serieTaylor(mpf_t *e, int n, int thread_count) {
    printf("\nQuantidade de threads: %d\n", thread_count);

    mpf_t partial_results[2];
    mpf_init2(partial_results[0], 16777216);
    mpf_init2(partial_results[1], 16777216);

    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int start = (my_rank == 0) ? 0 : 1;
        partial_sum(partial_results[my_rank], start, n, 2);
    }

    mpf_add(*e, partial_results[0], partial_results[1]);

    mpf_clear(partial_results[0]);
    mpf_clear(partial_results[1]);
}

// Restante do código...


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

    serieTaylor(&e, n, thread_count);

    gmp_printf("\nResultado: Salvo");
    save_to_file(e, "resultadoParaleloTeste.txt");
    mpf_clear(e);
    return 0;
}
