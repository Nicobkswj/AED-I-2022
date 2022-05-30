//Construa um programa para resolver o exercicio 8 da lista 3.1 (parte 1).
//O programa deve receber a entrada pela linha de comando.

//Exemplo de execucao: prog 478.90

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sa�das permitidas e que NAO PODEM ser modificadas
#define SAIDA_1 "\nSAIDA_1 = O salario antes do reajuste: R$ %.2f"
#define SAIDA_2 "\nSAIDA_2 = O salario reajustado ficou: R$ %.2f"
#define SAIDA_3 "\nSAIDA_3 = O percentual de reajuste foi de: %d%%"
#define SAIDA_4 "\nSAIDA_4 = O salario deve estar entre R$ 0,00 e R$ 1.000,00"

int main(int argc, char *argv[]) {

    float sal_at, sal_au;
    int pct_re;


    if( argc == 2 ) {
        //construa a solucao aqui
        sal_at = atof(argv[1]);
        //scanf("%f", &sal_at);

        if((sal_at >= 0) && (sal_at <= 1000)){
            if(sal_at <= 300){
                sal_au = sal_at * 1.35;
                pct_re = 35;
            }
            else{
                sal_au = sal_at * 1.15;
                pct_re = 15;
            }

            printf(SAIDA_1, sal_at);
            printf(SAIDA_2, sal_au);
            printf(SAIDA_3, pct_re);
        }
        else{
            printf(SAIDA_4);
        }

    }

    return 0;
}
