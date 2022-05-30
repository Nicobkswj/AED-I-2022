//Construa um programa para resolver o exercicio 21 da lista 3.1 (parte 1).
//O programa deve receber as entradas pela linha de comando.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//saídas permitidas e que nao devem ser modificadas
#define SAIDA_1 "\nSAIDA_1 = Para o codigo de origem %d e preco %.2f a procedencia vale: %s\n"
#define SAIDA_2 "\nSAIDA_2 = O preco e invalido, deve ser um valor maior que ZERO!\n"
#define SAIDA_3 "\nSAIDA_3 = O codigo de origem e invalido!\n"

int main(int argc, char *argv[]) 
{

    if( argc == 3 ) 
    {
        //construa a solucao aqui
        int cod;
        float vlr;
        char *proc;

        cod = atoi(argv[1]);
        vlr = atof(argv[2]);

        if ((cod > 0) && (cod <= 30) && (vlr > 0)) 
        {
            if(cod == 1)
                proc = "Sul";
            else if(cod == 2)
                proc = "Norte";
            else if(cod == 3)
                proc = "Leste";
            else if(cod == 4)
                proc = "Oeste";
            else if((cod == 5) || (cod == 6) || (cod > 20))
                proc = "Nordeste";
            else if((cod == 7) || (cod == 8) || (cod == 9))
                proc = "Sudeste";
            else
                proc = "Centro-Oeste";

            printf(SAIDA_1, cod, vlr, proc);
        } 
        else 
        {
            if(vlr <= 0)
                printf(SAIDA_2);
            if((cod <= 0) || (cod > 30))
                printf(SAIDA_3);
        }

    } 


    return 0;
}