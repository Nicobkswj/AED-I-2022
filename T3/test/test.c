#include <stdio.h>
#include <stdlib.h>

int main(){
    int vlr, pot, aux, condicao = 0, i;
    int vlrVetor[6];
    
    do{
        printf("Insira um número entre 0 e 188600: ");
        scanf(" %d", &vlr);
    }while((vlr < 0) || (vlr > 188600));

    if(vlr == 0){
        printf("zero real.\n");
    }
    else
    {
        pot = 1000000;
        for (i = 0; i < 6; i++)
        {
            aux = (vlr % pot) / (pot / 10);
            vlrVetor[i] = aux;
            pot /= 10;
        }
        for (i = 0; i < 6; i++)
        {
            printf("\n %d",vlrVetor[i]);
        }
        
        if (vlrVetor[0] == 1)
        {
            if (vlr / 1000 > 100)
            printf("cento e ");
            else if(vlr == 100000)
            printf("cem mil");
            else
            printf("cem mil e ");
        }
        if(vlrVetor[1]  > 0)
        {
            if(vlrVetor[1] == 1)
            condicao = 1;
            else{
                if (vlrVetor[1] == 2)
                printf("vinte ");
                if (vlrVetor[1] == 3)
                printf("trinta ");
                if (vlrVetor[1] == 4)
                printf("quarenta ");
                if (vlrVetor[1] == 5)
                printf("cinquenta ");
                if (vlrVetor[1] == 6)
                printf("sessenta ");
                if (vlrVetor[1] == 7)
                printf("setenta ");
                if (vlrVetor[1] == 8)
                printf("oitenta ");
                if (vlrVetor[1] == 9)
                printf("noventa ");
                if ((vlr / 1000) % 10 > 0)
                printf("e ");
                else
                printf("mil ");
            }
        }
        if (condicao == 1)
        {
            if(vlrVetor[2] == 0)
            printf("dez mil ");
            if(vlrVetor[2] == 1)
            printf("onze mil ");
            if(vlrVetor[2] == 2)
            printf("doze mil ");
            if(vlrVetor[2] == 3)
            printf("treze mil ");
            if(vlrVetor[2] == 4)
            printf("catorze mil ");
            if(vlrVetor[2] == 5)
            printf("quinze mil ");
            if(vlrVetor[2] == 6)
            printf("dezesseis mil ");
            if(vlrVetor[2] == 7)
            printf("dezessete mil ");
            if(vlrVetor[2] == 8)
            printf("dezoito mil ");
            if(vlrVetor[2] == 9)
            printf("dezenove mil ");

            condicao = 0;
        }
        else
        {
            if(vlrVetor[2] == 1)
            printf("mil ");
            if(vlrVetor[2] == 2)
            printf("dois mil ");
            if(vlrVetor[2] == 3)
            printf("tres mil ");
            if(vlrVetor[2] == 4)
            printf("quatro mil ");
            if(vlrVetor[2] == 5)
            printf("cinco mil ");
            if(vlrVetor[2] == 6)
            printf("seis mil ");
            if(vlrVetor[2] == 7)
            printf("sete mil ");
            if(vlrVetor[2] == 8)
            printf("oito mil ");
            if(vlrVetor[2] == 9)
            printf("nove mil ");
        }
        if((vlr % 1000 > 0) && (vlrVetor[2] > 0))
        printf("e ");
        
        if (vlrVetor[3] > 0)
        {
            if (vlrVetor[3]== 1)
            {
                if (vlr % 100 > 0)
                printf("cento ");
                else 
                printf("cem ");
            }
            if(vlrVetor[3] == 2)
            printf("duzentos ");
            if(vlrVetor[3] == 3)
            printf("trezentos ");
            if(vlrVetor[3] == 4)
            printf("quatrocentos ");
            if(vlrVetor[3] == 5)
            printf("quinhentos ");
            if(vlrVetor[3] == 6)
            printf("seiscentos ");
            if(vlrVetor[3] == 7)
            printf("setecentos ");
            if(vlrVetor[3] == 8)
            printf("oitocentos ");
            if(vlrVetor[3] == 9)
            printf("novecentos ");
            if (vlr % 100 > 0)
            printf("e ");
        }
        if(vlrVetor[4] > 0)
        {
            if(vlrVetor[4] == 1)
            condicao = 1;
            else{
                if (vlrVetor[4] == 2)
                printf("vinte ");
                if (vlrVetor[4] == 3)
                printf("trinta ");
                if (vlrVetor[4] == 4)
                printf("quarenta ");
                if (vlrVetor[4] == 5)
                printf("cinquenta ");
                if (vlrVetor[4] == 6)
                printf("sessenta ");
                if (vlrVetor[4] == 7)
                printf("setenta ");
                if (vlrVetor[4] == 8)
                printf("oitenta ");
                if (vlrVetor[4] == 9)
                printf("noventa ");
                if (vlr % 10 > 0)
                printf("e ");
            }
        }
    
        if (condicao == 1)
        {
            if(vlrVetor[5] == 0)
            printf("dez ");
            if(vlrVetor[5] == 1)
            printf("onze ");
            if(vlrVetor[5] == 2)
            printf("doze ");
            if(vlrVetor[5] == 3)
            printf("treze ");
            if(vlrVetor[5] == 4)
            printf("catorze ");
            if(vlrVetor[5] == 5)
            printf("quinze ");
            if(vlrVetor[5] == 6)
            printf("dezesseis ");
            if(vlrVetor[5] == 7)
            printf("dezessete ");
            if(vlrVetor[5] == 8)
            printf("dezoito ");
            if(vlrVetor[5] == 9)
            printf("dezenove ");

            condicao = 0;
        }
        else
        {
            if(vlrVetor[5] == 1)
            printf("um ");
            if(vlrVetor[5] == 2)
            printf("dois ");
            if(vlrVetor[5] == 3)
            printf("tres ");
            if(vlrVetor[5] == 4)
            printf("quatro ");
            if(vlrVetor[5] == 5)
            printf("cinco ");
            if(vlrVetor[5] == 6)
            printf("seis ");
            if(vlrVetor[5] == 7)
            printf("sete ");
            if(vlrVetor[5] == 8)
            printf("oito ");
            if(vlrVetor[5] == 9)
            printf("nove ");
        }
    }

    return 0;
}