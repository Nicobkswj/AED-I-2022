//Faca um programa que informa as duas maiores alturas das moças de um concurso de beleza.
//A altura deve estar entre 1.50 e 2.35 e podem existir alturas iguais.
//A quantidade de moças termina quando a ultima altura é 0.

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_PRIMEIRA_MAIOR_ALTURA "\nSAIDA_PRIMEIRA_MAIOR_ALTURA = %.2f"
#define SAIDA_SEGUNDA_MAIOR_ALTURA "\nSAIDA_SEGUNDA_MAIOR_ALTURA = %.2f"
#define SAIDA_ALTURA_FORA_LIMITE "\nSAIDA_ALTURA_FORA_LIMITE = %.2f"

//Exemplo de execucao: main.al.exe 1.6 1.85 1.71 1.93 1.89 1.74 1.80 0
//SAIDA_PRIMEIRA_MAIOR_ALTURA = 1.93
//SAIDA_SEGUNDA_MAIOR_ALTURA =  1.89


//Exemplo de execucao: main.al.exe 1.6 1.10 1.85 1.71 1.93 2.99 1.89 1.74 1.80 0
//SAIDA_ALTURA_FORA_LIMITE = 1.10
//SAIDA_ALTURA_FORA_LIMITE = 2.99
//SAIDA_PRIMEIRA_MAIOR_ALTURA = 1.93
//SAIDA_SEGUNDA_MAIOR_ALTURA = 1.89


int main (int numargs, char *arg[]) {

    //coloque aqui sua solucao
    int i;
    float h = 0, pma, sma;

    pma = 1.49;
    sma = 1.49;

    if(numargs > 1){
        for (i = 1; i < numargs; i++){
            h = atof(arg[i]);
            if(h == 0)
                i = numargs;
            else if((h < 1.5) || ( h > 2.35))
                printf(SAIDA_ALTURA_FORA_LIMITE, h);
            else if(h > pma){
                sma = pma;
                pma = h;
            }else if(h > sma)
                sma = h;
            
        }
        printf(SAIDA_PRIMEIRA_MAIOR_ALTURA, pma);
        printf(SAIDA_SEGUNDA_MAIOR_ALTURA, sma);
        return(0);
    }else{
        printf("\nerro");
        return(-1);
    }
}