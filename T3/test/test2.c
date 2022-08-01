#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int main()
{
    int vlrSaque, auxSaque, i;
    int vlrSaldo = 188600, saqueTotal = 0; 
    int saqueNotas[8], notas[8]= {450, 250, 50, 20, 10, 5, 2, 1}, saldoNotas[8] = {100, 200, 400, 800, 1600, 3200, 6400, 12800};

    printf("\nInforme o valor do saque: ");
    scanf("%d", &vlrSaque);
    
    while (vlrSaque <= 0)
    {
        printf("\nO valor do saque deve ser positivo. Tente novamente: ");
        scanf("%d", &vlrSaque);
    }

    if (vlrSaque > vlr_saldo)
    {
        printf("Notas no caixa insuficientes para realizar este saque. \n");
        break;
    }
    
    auxSaque = vlrSaque;
    saqueTotal += vlrSaque;

    for (i = 0; i < 8; i++)
        saqueNotas[i] = 0;    

    for (i = 0; i < 8; i++)
    {
        while (auxSaque >= notas[i])
        {
            if(saldoNotas[i] == 0)
                break;
            vlrSaldo -= notas[i];
            auxSaque -= notas[i];
            saqueNotas[i]++;
            saldoNotas[i]--;
        }
    }

    printf("\nSaque realizado com sucesso!\nQuantidade de notas necessarias:");
    for (i = 0; i < 8; i++)
        printf("\n%d de R$%d,00.", saqueNotas[i], notas[i]);
    

    return 0;

}
