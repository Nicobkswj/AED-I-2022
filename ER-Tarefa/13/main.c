/* Faça um programa que receba via argumento do programa dois numeros inteiros positivos A e B,
   onde B deve ser maior ou igual a A. O programa deve mostrar os números primos entre A e B,
   inclusive os extremos A e B.
*/

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nSAIDA_1 = Os primos entre A (%d) e B (%d) sao:"
#define SAIDA_2 "\nPrimo = %d"
#define SAIDA_3 "\nSAIDA_3 = O valor de B (%d) e menor que o valor de A (%d)"
#define SAIDA_4 "\nSAIDA_4 = Quantidade invalida de argumentos!"
#define SAIDA_5 "\nSAIDA_5 = Um dos argumentos nao e positivo!"
#define SAIDA_6 "\nSAIDA_6 = Nao existe nenhum primo no intervalo entre A (%d) e B(%d)!"

/* exemplos de execucao

	app.exe 
		SAIDA_4 = Quantidade invalida de argumentos!

	app.exe 5 -1
		SAIDA_3 = O valor de B (-1) e menor que o valor de A (5)
		SAIDA_5 = Um dos argumentos nao e positivo!

	app.exe -1 5
		SAIDA_5 = Um dos argumentos nao e positivo!

	app.exe 2 6
		SAIDA_1 = Os primos entre A (2) e B (6) sao:
		Primo = 2
		Primo = 3
		Primo = 5
*/

int main(int argc, char *argv[])
{
    //coloque aqui sua solucao
    if (argc == 3){    
        int A, B, i, j, p, np = 0, cont = 1;

        A = atoi(argv[1]);
        B = atoi(argv[2]);
        
        if ((A <= B) && (A > 0) && (B > 0)){
            for (i = A; i < B; i++)
            {
                p = 0;
                for (j = 2; j < i; j++)
                {  
                    if (i % j == 0)
                    p++;
                }
                if (p == 0){
                    if (cont == 1)
                    printf(SAIDA_1, A, B); 

                    printf(SAIDA_2, i);
                    cont++;
                }else
                np++;
            }
            if (np == (B - A))
            printf(SAIDA_6, A, B);
            
        }else{
            if (A > B)
            printf(SAIDA_3, B, A);
            if ((A < 0) || (B < 0))
            printf(SAIDA_5);
        }
        

        return 0;
    }
    else{
        printf(SAIDA_4);
        return -1;
    }
    
}