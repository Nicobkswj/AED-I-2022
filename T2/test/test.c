#include <stdio.h>
#include <stdlib.h>

int main(){
    int njk, pot, aux_c, condicao = 0;
    
    do{
    printf("Insira um número entre 0 e 188600: ");
    scanf("%d", &njk);
    }while((njk < 0) || (njk > 188600));

    pot = 1000000;

    if(njk == 0){
        printf("zero real.\n");
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            aux_c = (njk % pot) / (pot / 10);
            //printf("\n%d", aux_c);
            pot /= 10;
            if ((i == 0) && (aux_c == 1))
            {
                if (njk / 1000 > 100)
                printf("cento e ");
                else if(njk == 100000)
                printf("cem mil");
                else
                printf("cem mil e ");
            }
            if((i == 1) && (aux_c > 0))
            {
                if(aux_c == 1)
                condicao = 1;
                else{
                    if (aux_c == 2)
                    printf("vinte ");
                    if (aux_c == 3)
                    printf("trinta ");
                    if (aux_c == 4)
                    printf("quarenta ");
                    if (aux_c == 5)
                    printf("cinquenta ");
                    if (aux_c == 6)
                    printf("sessenta ");
                    if (aux_c == 7)
                    printf("setenta ");
                    if (aux_c == 8)
                    printf("oitenta ");
                    if (aux_c == 9)
                    printf("noventa ");
                    if ((njk / 1000) % 10 > 0)
                    printf("e ");
                    else
                    printf("mil ");
                }
            }
            if (i == 2)
            {
                if (condicao == 1)
                {
                    if(aux_c == 0)
                    printf("dez mil ");
                    if(aux_c == 1)
                    printf("onze mil ");
                    if(aux_c == 2)
                    printf("doze mil ");
                    if(aux_c == 3)
                    printf("treze mil ");
                    if(aux_c == 4)
                    printf("catorze mil ");
                    if(aux_c == 5)
                    printf("quinze mil ");
                    if(aux_c == 6)
                    printf("dezesseis mil ");
                    if(aux_c == 7)
                    printf("dezessete mil ");
                    if(aux_c == 8)
                    printf("dezoito mil ");
                    if(aux_c == 9)
                    printf("dezenove mil ");

                    condicao = 0;
                }
                else
                {
                    if(aux_c == 1)
                    printf("mil ");
                    if(aux_c == 2)
                    printf("dois mil ");
                    if(aux_c == 3)
                    printf("tres mil ");
                    if(aux_c == 4)
                    printf("quatro mil ");
                    if(aux_c == 5)
                    printf("cinco mil ");
                    if(aux_c == 6)
                    printf("seis mil ");
                    if(aux_c == 7)
                    printf("sete mil ");
                    if(aux_c == 8)
                    printf("oito mil ");
                    if(aux_c == 9)
                    printf("nove mil ");
                }
                if((njk % 1000 > 0) && (aux_c > 0))
                printf("e ");
            }
            if ((i == 3) && (aux_c > 0))
            {
                if (aux_c == 1)
                {
                    if (njk % 100 > 0)
                    printf("cento ");
                    else 
                    printf("cem ");
                }
                if(aux_c == 2)
                printf("duzentos ");
                if(aux_c == 3)
                printf("trezentos ");
                if(aux_c == 4)
                printf("quatrocentos ");
                if(aux_c == 5)
                printf("quinhentos ");
                if(aux_c == 6)
                printf("seiscentos ");
                if(aux_c == 7)
                printf("setecentos ");
                if(aux_c == 8)
                printf("oitocentos ");
                if(aux_c == 9)
                printf("novecentos ");
                if (njk % 100 > 0)
                printf("e ");
            }
            if((i == 4) && (aux_c > 0))
            {
                if(aux_c == 1)
                condicao = 1;
                else{
                    if (aux_c == 2)
                    printf("vinte ");
                    if (aux_c == 3)
                    printf("trinta ");
                    if (aux_c == 4)
                    printf("quarenta ");
                    if (aux_c == 5)
                    printf("cinquenta ");
                    if (aux_c == 6)
                    printf("sessenta ");
                    if (aux_c == 7)
                    printf("setenta ");
                    if (aux_c == 8)
                    printf("oitenta ");
                    if (aux_c == 9)
                    printf("noventa ");
                    if (n % 10 > 0)
                    printf("e ");
                }
            }
            if (i == 5)
            {
                if (condicao == 1)
                {
                    if(aux_c == 0)
                    printf("dez ");
                    if(aux_c == 1)
                    printf("onze ");
                    if(aux_c == 2)
                    printf("doze ");
                    if(aux_c == 3)
                    printf("treze ");
                    if(aux_c == 4)
                    printf("catorze ");
                    if(aux_c == 5)
                    printf("quinze ");
                    if(aux_c == 6)
                    printf("dezesseis ");
                    if(aux_c == 7)
                    printf("dezessete ");
                    if(aux_c == 8)
                    printf("dezoito ");
                    if(aux_c == 9)
                    printf("dezenove ");

                    condicao = 0;
                }
                else
                {
                    if(aux_c == 1)
                    printf("um ");
                    if(aux_c == 2)
                    printf("dois ");
                    if(aux_c == 3)
                    printf("tres ");
                    if(aux_c == 4)
                    printf("quatro ");
                    if(aux_c == 5)
                    printf("cinco ");
                    if(aux_c == 6)
                    printf("seis ");
                    if(aux_c == 7)
                    printf("sete ");
                    if(aux_c == 8)
                    printf("oito ");
                    if(aux_c == 9)
                    printf("nove ");
                }
            }
        }

        printf("reais.\n");
    }

    return 0;
}