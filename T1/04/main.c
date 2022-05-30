//Máquina de Café
//Alunos: Nicolas Rocha, Kauan Henrik, Igor Nunes, Lucas Rodrigues, Gabriel Azevedo & Luiz Felipe Silva.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIDA_1 "\nTempo: %d"


int main(){

    int func_a1, func_a2, func_a3, tempo_a1, tempo_a2, tempo_a3;

    do
    {
        printf("\nInsira a quantidade de funcionários no andar 1: ");
        scanf("%d", &func_a1);
    } while ((func_a1 < 0) || (func_a1 > 1000));
    do
    {
        printf("\nInsira a quantidade de funcionários no andar 2: ");
        scanf("%d", &func_a2);
    } while ((func_a2 < 0) || (func_a2 > 1000));
    do
    {
        printf("\nInsira a quantidade de funcionários no andar 3: ");
        scanf("%d", &func_a3);
    } while ((func_a3 < 0) || (func_a3 > 1000));

    tempo_a1 = (func_a2  + (func_a3 * 2)) * 2;
    tempo_a2 = (func_a1  + func_a3) * 2;
    tempo_a3 = ((func_a1 * 2)  + func_a2) * 2;

    if ((tempo_a1 <= tempo_a2) && (tempo_a1 <= tempo_a3))
    {
        printf(SAIDA_1, tempo_a1);
        printf("\nMaquina localizada no(s) andar(es): 1");
        if (tempo_a1 == tempo_a2)
        printf(" OU 2");
        if (tempo_a1 == tempo_a3)
        printf(" OU 3");
    }
    else if ((tempo_a2 <= tempo_a1) && (tempo_a2 <= tempo_a3))
    {
        printf(SAIDA_1, tempo_a2);
        printf("\nMaquina localizada no(s) andar(es): 2");
        if (tempo_a2 == tempo_a3)
        printf(" OU 3");
    }
    else if ((tempo_a3 <= tempo_a1) && (tempo_a3 <= tempo_a2))
    {
        printf(SAIDA_1, tempo_a3);
        printf("\nMaquina localizada no(s) andar(es): 3");
    }
    return 0;
}
