#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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



void serieTaylor(mpf_t *e, mpf_t x, int n){
    mpf_t fat, fate;
    mpf_init2(fat,2097152);
    mpf_init2(fate,2097152);
    mpf_set_ui(fat,0);
    mpf_set_ui(fate,0);
    //long double e = 0;
    for(int i = 0; i < n; i++){
        fatorial(&fat,i); //Realizo o fatorial de i e armazeno em fat
        mpf_div(fate,x,fat); //Realizo a divisao de X(1) com o fat 
        mpf_add(*e,*e,fate); //Adiciono em e o valor dessa divisao
        //mpf_add_ui(fat,fat,1);
        //e += x/fatorial(i);
        //gmp_printf("Valor atual do e: %Ff\n",e);
        //printf("Valor atual de e = %Lf\n",e);
    }
}


int main(void) {
    int n = 0;
    mpf_t e,x;
    mpf_init2(e,2097152);
    mpf_init2(x,2097152);
    mpf_set_ui(e,0);
    mpf_set_ui(x,1);
    printf("Insira o n: ");
    scanf("%d", &n);
    printf("Valor de n = %d\n",n);
    serieTaylor(&e,x,n);
    gmp_printf("\nResultado: %.50000Ff\n",e);
    mpf_clear(e);
    mpf_clear(x);
    return 0;
}
