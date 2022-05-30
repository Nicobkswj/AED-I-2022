/*Faca um programa que receba pelo argumento do programa uma lista de numeros inteiros entre 0 e 10.
  O programa deve calcular e mostrar o valor do fatorial de cada numero da lista e tamb�m informar:
  a somatoria dos fatoriais, a m�dia dos fatoriais, o maior fatorial e o segundo menor fatorial.
*/

/* Exemplos de execucao

    1- app.exe
            SAIDA_2 = O_PROGRAMA_NAO_TEM_SAIDA!

    2- app.exe 50
            NUMERO_INVALIDO_LISTA = 50

    3- app.exe 1 2 3
            O_FATORIAL_DE = (1) VALE 1
            O_FATORIAL_DE = (2) VALE 2
            O_FATORIAL_DE = (3) VALE 6
            SOMA_FATORIAL = 9
            MEDIA_FATORIAL = 3.0
            MAIOR_FATORIAL = 6
            SEGUNDO_MENOR_FATORIAL = 2

    4- app.exe 1 -9 3
        O_FATORIAL_DE = (1) VALE 1
        NUMERO_INVALIDO_LISTA = -9
        O_FATORIAL_DE = (3) VALE 6
        SOMA_FATORIAL = 7
        MEDIA_FATORIAL = 3.5
        MAIOR_FATORIAL = 6
        SEGUNDO_MENOR_FATORIAL = 6

    5- app.exe 1 -9
        O_FATORIAL_DE = (1) VALE 1
        NUMERO_INVALIDO_LISTA = -9
        SOMA_FATORIAL = 1
        MEDIA_FATORIAL = 1.0
        MAIOR_FATORIAL = 1
        SAIDA_1 = SEGUNDO_MENOR_FATORIAL_INEXISTENTE

    6- app.exe 3 1 3
        O_FATORIAL_DE = (3) VALE 6
        O_FATORIAL_DE = (1) VALE 1
        O_FATORIAL_DE = (3) VALE 6
        SOMA_FATORIAL = 13
        MEDIA_FATORIAL = 4.3
        MAIOR_FATORIAL = 6
        SEGUNDO_MENOR_FATORIAL = 6
*/

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_O_FATORIAL_VALE "\nO_FATORIAL_DE = (%d) VALE %0.f"
#define SAIDA_SOMA_FATORIAL "\nSOMA_FATORIAL = %.0f"
#define SAIDA_MEDIA_FATORIAL "\nMEDIA_FATORIAL = %.1f"
#define SAIDA_MAIOR_FATORIAL "\nMAIOR_FATORIAL = %.0f"
#define SAIDA_SEGUNDO_MENOR_FATORIAL "\nSEGUNDO_MENOR_FATORIAL = %.0f"
#define SAIDA_SEGUNDO_MENOR_FATORIAL_INEXISTENTE "\nSAIDA_1 = SEGUNDO_MENOR_FATORIAL_INEXISTENTE"
#define SAIDA_NUMERO_INVALIDO_LISTA "\nNUMERO_INVALIDO_LISTA = %d"
#define SAIDA_O_PROGRAMA_NAO_TEM_SAIDA "\nSAIDA_2 = O_PROGRAMA_NAO_TEM_SAIDA!"

int main (int numargs, char *argv[]) {

    //insira aqui sua solucao
    int i, j, n; 
    float fat, soma = 0, media = 1, maior, menor, smenor;
    
    if (numargs > 1)
    {
        maior = 0;
        menor = 3628800;

        for ( i = 1; i < numargs; i++)
        {
            fat = 1;
            j = 1;
            n = atoi(argv[i]);

            if ((n < 0) || (n > 10)) 
                printf(SAIDA_NUMERO_INVALIDO_LISTA, n);
            else{
                do
                {
                    fat = j * fat;
                    j++;
                }while (j <= n);

                soma = soma + fat;
                media = media * fat;
                
                if(numargs > 2){
                    if(fat < menor){
                        smenor = menor;
                        menor = fat;
                    }
                    else
                    { 
                        if (i == 2)
                            smenor = fat;
                        else if (fat < smenor)
                           smenor = fat;
                    
                    }
                }
                if (fat > maior)
                    maior = fat;                

                printf(SAIDA_O_FATORIAL_VALE, n, fat);
            }
        }
        
        media = media / numargs;

        printf(SAIDA_SOMA_FATORIAL, soma);
        printf(SAIDA_MEDIA_FATORIAL, media);
        printf(SAIDA_MAIOR_FATORIAL, maior);
        if (numargs == 2)
            printf(SAIDA_SEGUNDO_MENOR_FATORIAL_INEXISTENTE);
        else
            printf(SAIDA_SEGUNDO_MENOR_FATORIAL, smenor);
        
        
        
        return(0);
    }
    else
    {
        printf(SAIDA_O_PROGRAMA_NAO_TEM_SAIDA);
        return(-1);
    }
    
    


}
