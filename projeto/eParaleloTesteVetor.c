#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

void serieTaylor(mpf_t *e, int n, int thread_count) {
    printf("\nQuantiade de threads: %d\n",thread_count);

    // Pré-calcular os termos iniciais e armazená-los em um vetor
    mpf_t initial_terms[thread_count];
    mpf_t term;
    mpf_init2(term, 16777216);
    mpf_set_ui(term, 1);

    for (int i = 0; i < thread_count; i++) {
        mpf_init2(initial_terms[i], 16777216);
        mpf_set(initial_terms[i], term);
        int local_n = n / thread_count;
        for (int j = 0; j < local_n; j++) {
            mpf_div_ui(term, term, (i * local_n) + j + 1);
        }
    }

    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int local_n = n / thread_count;
        int start = my_rank * local_n;
        int end = (my_rank + 1) * local_n - 1;

        if (my_rank == thread_count - 1)
            end = n;

        mpf_t elocal;
        mpf_init2(elocal, 16777216);
        mpf_set_ui(elocal, 0);

        // Iniciar com o termo inicial correto armazenado no vetor
        mpf_set(term, initial_terms[my_rank]);

        printf("\nEu sou a thread: %d e estou calculando de %d até %d", my_rank, start, end);

        for (int i = start; i <= end; ++i) {
            mpf_add(elocal, elocal, term);
            mpf_div_ui(term, term, i + 1);
        }

        #pragma omp critical
        mpf_add(*e, *e, elocal);

        mpf_clear(elocal);
    }

    // Limpar memória
    for (int i = 0; i < thread_count; i++) {
        mpf_clear(initial_terms[i]);
    }
    mpf_clear(term);
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
    mpf_t e;
    mpf_init2(e, 16777216);
    mpf_set_ui(e, 0);
    int thread_count = strtol(argv[1], NULL, 10);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n", n);

    serieTaylor(&e, n, thread_count);

    gmp_printf("\nResultado: Salvo");
    save_to_file(e, "resultadoParalelo.txt");
    mpf_clear(e);
    return 0;
}
