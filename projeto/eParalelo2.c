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

void serieTaylor(mpf_t *e, mpf_t x, int n) {
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
    //local_n = (n + 1) / thread_count * (my_rank + 1);
    //local_i = (n + 1) / thread_count * my_rank;
    //printf("MY RANK:%d\n", my_rank);
    //printf("thread_count:%d\n", thread_count);
    //printf("local_i: %d local_n: %d\n", local_i, local_n);
    if(my_rank == 0){
        for (int i = 0; i < n; i+=2) {
            fatorial(&fat,i); //Realizo o fatorial de i e armazeno em fat
            mpf_div(fate,x,fat); //Realizo a divisao de X(1) com o fat 
            mpf_add(elocal,elocal,fate); //Adiciono em e o valor dessa divisao
        }
    }
    else{
        for (int i = 1; i <= n; i+=2) {
            fatorial(&fat,i); //Realizo o fatorial de i e armazeno em fat
            mpf_div(fate,x,fat); //Realizo a divisao de X(1) com o fat 
            mpf_add(elocal,elocal,fate); //Adiciono em e o valor dessa divisao
        }
    }
    
    #pragma omp critical
    mpf_add(*e,*e,elocal);
    //*global_e += e;
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
    mpf_t e,x;
    mpf_init2(e,2097152);
    mpf_init2(x,2097152);
    mpf_set_ui(e,0);
    mpf_set_ui(x,1);
    int thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n",n);
    #pragma omp parallel num_threads(thread_count)
    serieTaylor(&e,x,n);
    gmp_printf("\nResultado salvo!\n");
    save_to_file(e, "resultado.txt");
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}
