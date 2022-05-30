//Elevador Espacial
//Alunos: Nicolas Rocha, Kauan Henrik, Igor Nunes, Lucas Rodrigues, Gabriel Azevedo & Luiz Felipe Silva.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){



    int i, n, c = 0, j, h, pot;
    int aux_a, aux_b, aux_c, aux_d;

    printf("Insira o andar: ");
    scanf("%d", &n);
    while ((n<=0) || (n > 1000000))
    {
        printf("\n\nO valor do andar deve ser positivo e menor que 1000000.\nTente Novamente: ");
        scanf("%d", &n);

    }


    for ( i = 1; i <= n; i++){
        c++;
        do{
            h = 0;
            pot = 1;

            for (j = 0; j < 7; j++)
            {
                aux_a = c / pot;
                aux_b = c %  pot;
                if(j >= 2)
                aux_c = (c % pot) / (pot / 10);
                if(j >= 3)
                aux_d = (c % pot) / (pot / 100);

                if ((aux_a == 4) || (aux_a == 13) || (aux_b == 4) || (aux_b == 13) || (aux_c == 4) || (aux_d == 13))
                h++;

                pot *= 10;
            }
            if (h > 0)
            c++;
        }while(h > 0);

        //printf("\n%d   %d", i, c);
    }
    printf("\nO andar equivalente ao %d, sera o %d.", n, c);

    return 0;
}
