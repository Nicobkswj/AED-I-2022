//Faca um programa que receba um número inteiro, positivo N, pela linha de comando,
//calcule e mostre o maior quadrado menor ou igual a N.
//Por exemplo, se N for maior ou igual a 38, o menor quadrado é 36 (quadrado de 6).
//Por exemplo, se N for maior ou igual a 48, o menor quadrado é 36 (quadrado de 6).
//Por exemplo, se N for maior ou igual a 95, o menor quadrado é 81 (quadrado de 9).


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//saídas permitidas e que nao devem ser modificadas
#define SAIDA_1 "\nSAIDA_1 = O maior quadrado menor ou igual a N vale: %d\n"
#define SAIDA_2 "\nSAIDA_2 = N invalido, deve ser um valor positivo!\n"
#define SAIDA_3 "\nSAIDA_3 = Quantidade de argumento invalido!\n"

int main(int argc, char *argv[]) {

    if( argc == 2 ) {
        //construa a solucao aqui
        int i = 0, n1, n2;
        
        n2 = atoi(argv[1]);

        if(n2 > 0) {
            do{
                i++;
                n1 = i * i;
            }while(n1 <= n2);

            i--;
            n1 = i * i;

            printf(SAIDA_1, n1);
        }
        else
            printf(SAIDA_2);

	    return 0;
    } else {
	    printf(SAIDA_3);
    	return -1;
    }
}