#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <gmp.h>

void fatorial(mpf_t resultado, int n) {
    mpf_set_ui(resultado, 1); // Inicializa o resultado com 1

    for (int i = 2; i <= n; i++) {
        mpf_t temp;
        mpf_init_set_ui(temp, i); // Inicializa temp com i
        mpf_mul(resultado, resultado, temp); // result = result * temp
        mpf_clear(temp); // Libera a memória alocada para temp
    }
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
        mpf_init2(term, 33554432);
        mpf_init2(elocal, 33554432);
        mpf_set_ui(term, 1);
        mpf_set_ui(elocal, 0);
        
        fatorial(term,start);
        mpf_ui_div(term,1,term);

        for (int i = start; i <= end; ++i) {
            mpf_add(elocal, elocal, term);
            mpf_div_ui(term, term, i + 1);
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
    gmp_fprintf(file, "%.100000000Ff\n", e);
    fclose(file);
}

int main(int argc, char *argv[]) {
    int n = 0;
    mpf_t e;
    mpf_init2(e, 33554432);
    mpf_set_ui(e, 0);
    int thread_count = strtol(argv[1], NULL, 10);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n", n);
    serieTaylor(e, n, thread_count);
    save_to_file(e, "resultadoParaleloTesteMac.txt");
    printf("\nResultado salvo!");
    gmp_printf("\nPrévia do resultado: %.15Ff",e);
    mpf_clear(e);
    return 0;
}
