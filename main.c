//T2 - Caixa eletronico
//Alunos: Nicolas Rocha, Kauan Henrik, Igor Nunes, Lucas Rodrigues, Gabriel Azevedo & Luiz Felipe Silva.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    //Variáveis para o menu de opções 
    int menuPrincipal, menuGerente, menuAbastecer;
    //Variáveis para a validação CPF
    long long cpf, pot;
    int aux_a, aux_b, cont_a, pd, sd, soma_pd, soma_sd, vld_pd, vld_sd;
    //Variáveis para escrever por extenso
    int aux_c, condicao = 0;
    //Variáveis para o caixa
    int vlr_saldo = 188600, vlr_total = 0, vlr_saque, aux_saque;
    int saque_450, saque_250, saque_50, saque_20, saque_10, saque_5, saque_2, saque_1;
    int saldo_450 = 100, saldo_250 = 200, saldo_50 = 400, saldo_20 = 800, saldo_10 = 1600, saldo_5 = 3200, saldo_2 = 6400, saldo_1 = 12800;

    do
    {
        printf("\nMENU PRINCIPAL\n");
        printf("\n(1) Saque");
        printf("\n(2) Gerente");
        printf("\n(3) Finalizar\n");
        scanf("%d", &menuPrincipal);

        switch (menuPrincipal)
        {
        case 1://Cliente
            printf("\nVoce escolheu saque.");
            printf("\nInsira o seu CPF: ");
            scanf("%lld", &cpf);
            pot = 10;
            cont_a = 0;
            soma_pd = 0;
            soma_sd = 0;

            for (i = 0; i < 11; i++)
            {
                aux_a = (cpf % pot) / (pot / 10);

                if (i == 0)
                sd = aux_a;
                else
                {
                    if((i < 10) || (aux_a > 0))
                    soma_sd += (aux_a * (i + 1));
                    if (i == 1)
                    pd = aux_a;
                    else
                    soma_pd += (aux_a * i);
                    if (aux_b == aux_a)
                    cont_a++;
                }

                pot*=10;
                aux_b = aux_a;
            }
            vld_pd = ((soma_pd * 10) % 11) % 10;
            vld_sd = ((soma_sd * 10) % 11) % 10;

            if ((vld_pd != pd) || (vld_sd != sd) || (cont_a == 10) || (cpf <= 0) || (cpf / (pot / 10) > 0))
            printf("\nCPF invalido! Tente novamente.\n");
            else
            {
                printf("CPF valido!");
                
                printf("\nInforme o valor do saque: ");
                scanf("%d", &vlr_saque);
                
                while (vlr_saque <= 0)
                {
                    printf("\nO valor do saque deve ser positivo. Tente novamente: ");
                    scanf("%d", &vlr_saque);
                }

                if ((vlr_saque > vlr_saldo) || ((vlr_saque % 10 != 0) && ((saldo_1 == 0) || (saldo_2 == 0))) || ((vlr_saque % 100 != 0) && ((saldo_10 == 0) || (saldo_20 == 0))))
                {
                    printf("Notas no caixa insuficientes para realizar este saque. \n");
                    break;
                }

                
                
                aux_saque = vlr_saque;
                vlr_total += vlr_saque;
                saque_450 = 0;
                saque_250 = 0;
                saque_50 = 0;
                saque_20 = 0;
                saque_10 = 0;
                saque_5 = 0;
                saque_2 = 0;
                saque_1 = 0;

                while (aux_saque >= 450)
                {
                    if(saldo_450 == 0)
                    break;
                    vlr_saldo -= 450;
                    aux_saque -= 450;
                    saque_450++;
                    saldo_450--;
                }
                while (aux_saque >= 250)
                {
                    if(saldo_250 == 0)
                    break;
                    vlr_saldo -= 250;
                    aux_saque -= 250;
                    saque_250++;
                    saldo_250--;
                }
                while (aux_saque >= 50)
                {
                    if(saldo_50 == 0)
                    break;
                    vlr_saldo -= 50;
                    aux_saque -= 50;
                    saque_50++;
                    saldo_50--;
                }
                while (aux_saque >= 20)
                {
                    if(saldo_20 == 0)
                    break;
                    vlr_saldo -= 20;
                    aux_saque -= 20;
                    saque_20++;
                    saldo_20--;
                }
                while (aux_saque >= 10)
                {
                    if(saldo_10 == 0)
                    break;
                    vlr_saldo -= 10;
                    aux_saque -= 10;
                    saque_10++;
                    saldo_10--;
                }
                while (aux_saque >= 5)
                {
                    if(saldo_5 == 0)
                    break;
                    vlr_saldo -= 5;
                    aux_saque -= 5;
                    saque_5++;
                    saldo_5--;
                }
                while (aux_saque >= 2)
                {
                    if(saldo_2 == 0)
                    break;
                    vlr_saldo -= 2;
                    aux_saque -= 2;
                    saque_2++;
                    saldo_2--;
                }
                while (aux_saque >= 1)
                {
                    if(saldo_1 == 0)
                    break;
                    vlr_saldo -= 1;
                    aux_saque -= 1;
                    saque_1++;
                    saldo_1--;
                }

                printf("Saque realizado com sucesso!\nQuantidade de notas necessarias: \n%d de R$450,00; \n%d de R$250,00; \n%d de R$50,00; \n%d de R$20,00; \n%d de R$10,00; \n%d de R$5,00; \n%d de R$2,00; \n%d de R$1,00.\n", saque_450, saque_250, saque_50, saque_20, saque_10, saque_5, saque_2, saque_1);		
                printf("\nO valor do saque foi de ");

                pot = 1000000;

                for (i = 0; i < 6; i++)
                {
                    aux_c = (vlr_saque % pot) / (pot / 10);
                    pot /= 10;

                    if ((i == 0) && (aux_c == 1))
                    {
                        if (vlr_saque / 1000 > 100)
                        printf("cento e ");
                        else if(vlr_saque == 100000)
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
                            if ((vlr_saque / 1000) % 10 > 0)
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
                        if((vlr_saque % 1000 > 0) && (aux_c > 0))
                        printf("e ");
                    }
                    if ((i == 3) && (aux_c > 0))
                    {
                        if (aux_c == 1)
                        {
                            if (vlr_saque % 100 > 0)
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
                        if (vlr_saque % 100 > 0)
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
                            if (vlr_saque % 10 > 0)
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

            break;
        case 2://Gerente
            do
            {
                printf("\nMENU GERENTE\n");
                printf("\n(1) Valor total sacado");
                printf("\n(2) Valor do saldo existente");
                printf("\n(3) Quantidade de cedulas existentes");
                printf("\n(4) Abastecer o caixa eletronico");
                printf("\n(5) Voltar ao menu principal\n");
                scanf("%d", &menuGerente);

                switch (menuGerente)
                {
                case 1:
                    printf("\nValor total sacado: R$%d,00 ou ", vlr_total);

                    pot = 1000000;

                    if(vlr_total == 0)
                        printf("zero real.\n");
                    else
                    {
                        for (i = 0; i < 6; i++)
                        {
                            aux_c = (vlr_total % pot) / (pot / 10);
                            pot /= 10;

                            if ((i == 0) && (aux_c == 1))
                            {
                                if (vlr_total / 1000 > 100)
                                printf("cento e ");
                                else if(vlr_total == 100000)
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
                                    if ((vlr_total / 1000) % 10 > 0)
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
                                if((vlr_total % 1000 > 0) && (aux_c > 0))
                                printf("e ");
                            }
                            if ((i == 3) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (vlr_total % 100 > 0)
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
                                if (vlr_total % 100 > 0)
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
                                    if (vlr_total % 10 > 0)
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

                    break;
                case 2:
                    printf("\nValor do saldo existente: R$%d,00 ou ", vlr_saldo);
                    pot = 1000000;

                    if(vlr_saldo == 0)
                        printf("zero real.\n");
                    else
                    {
                        for (i = 0; i < 6; i++)
                        {
                            aux_c = (vlr_saldo % pot) / (pot / 10);
                            pot /= 10;

                            if ((i == 0) && (aux_c == 1))
                            {
                                if (vlr_saldo / 1000 > 100)
                                printf("cento e ");
                                else if(vlr_saldo == 100000)
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
                                    if ((vlr_saldo / 1000) % 10 > 0)
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
                                if((vlr_saldo % 1000 > 0) && (aux_c > 0))
                                printf("e ");
                            }
                            if ((i == 3) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (vlr_saldo % 100 > 0)
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
                                if (vlr_saldo % 100 > 0)
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
                                    if (vlr_saldo % 10 > 0)
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
                    break;
                case 3:
                    printf("\nQuantidade de cedulas existentes: \n");
                    
                    pot = 1000;
                    if (saldo_450 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 3; i++)
                        {
                            aux_c = (saldo_450 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c == 1))
                            printf("cem ");
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
                                    if (saldo_450 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 2)
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
                                    printf("uma ");
                                    if(aux_c == 2)
                                    printf("duas ");
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

                    }
                    printf("(%d) nota(s) de R$450,00;\n", saldo_450);
                    
                    pot = 1000;
                    if (saldo_250 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 3; i++)
                        {
                            aux_c = (saldo_250 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c > 0))
                            {
                                if (saldo_250 == 100)
                                printf("cem ");
                                else if ((saldo_250 > 100) && (aux_c == 1))
                                printf("cento e ");
                                else
                                printf("duzentas ");                
                                
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
                                    if (saldo_250 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 2)
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

                    }
                    printf("(%d) nota(s) de R$250,00;\n", saldo_250);
                    
                    pot = 1000;
                    if (saldo_50 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 3; i++)
                        {
                            aux_c = (saldo_50 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_50 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if (saldo_50 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
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
                                    if (saldo_50 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 2)
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

                    }
                    printf("(%d) nota(s) de R$50,00;\n", saldo_50);

                    pot = 1000;
                    if (saldo_20 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 3; i++)
                        {
                            aux_c = (saldo_20 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_20 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if (saldo_20 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
                            }
                            if((i == 1) && (aux_c > 0))
                            {
                                if(aux_c == 1)
                                condicao = 1;
                                else {
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
                                    if (saldo_20 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 2)
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

                    }
                    printf("(%d) nota(s) de R$50,00;\n", saldo_20);

                    pot = 10000;
                    if (saldo_10 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 4; i++)
                        {
                            aux_c = (saldo_10 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c == 1))
                            {
                                printf("mil ");
                                if(saldo_10 % 1000 > 0)
                                printf("e ");
                            }
                            if((i == 1) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_10 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if(aux_c == 9)
                                printf("novecent");
                                if (saldo_10 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
                            }
                            if((i == 2) && (aux_c > 0))
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
                                    if (saldo_10 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 3)
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

                    }
                    printf("(%d) nota(s) de R$10,00;\n", saldo_10);

                    pot = 10000;
                    if (saldo_5 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 4; i++)
                        {
                            aux_c = (saldo_5 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c > 0))
                            {
                                if(aux_c == 1)
                                printf("mil ");
                                if(aux_c == 2)
                                printf("duas mil ");
                                if(aux_c == 3)
                                printf("tres mil ");
                                if(saldo_5 % 1000 > 0)
                                printf("e ");
                            }
                            if((i == 1) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_5 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if(aux_c == 9)
                                printf("novecent");
                                if (saldo_5 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
                            }
                            if((i == 2) && (aux_c > 0))
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
                                    if (saldo_5 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 3)
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

                    }
                    printf("(%d) nota(s) de R$5,00;\n", saldo_5);

                    pot = 10000;
                    if (saldo_2 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 4; i++)
                        {
                            aux_c = (saldo_2 % pot) / (pot / 10);
                            pot /= 10;

                            if((i == 0) && (aux_c > 0))
                            {
                                if(aux_c == 1)
                                printf("mil ");
                                if(aux_c == 2)
                                printf("duas mil ");
                                if(aux_c == 3)
                                printf("tres mil ");
                                if(aux_c == 4)
                                printf("quatro mil ");
                                if(aux_c == 5)
                                printf("cinco mil ");
                                if(aux_c == 6)
                                printf("seis mil ");
                                if(saldo_2 % 1000 > 0)
                                printf("e ");
                            }
                            if((i == 1) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_2 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if(aux_c == 9)
                                printf("novecent");
                                if (saldo_2 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
                            }
                            if((i == 2) && (aux_c > 0))
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
                                    if (saldo_2 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 3)
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

                    }
                    printf("(%d) nota(s) de R$2,00;\n", saldo_2);

                    pot = 100000;
                    if (saldo_1 == 0)
                    printf("zero ");
                    else
                    {
                        for (i = 0; i < 5; i++)
                        {
                            aux_c = (saldo_1 % pot) / (pot / 10);
                            pot /= 10;

                            if ((i == 0) && (aux_c == 1))
                            condicao = 1;
                            if((i == 1) && (aux_c > 0))
                            {
                                if (condicao == 1)
                                {
                                    if(aux_c == 0)
                                    printf("dez mil ");
                                    if(aux_c == 1)
                                    printf("onze mil ");
                                    if(aux_c == 2)
                                    printf("doze mil ");

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
                                if((saldo_1 % 1000 > 0) && (aux_c > 0))
                                printf("e ");
                            }
                            if((i == 2) && (aux_c > 0))
                            {
                                if (aux_c == 1)
                                {
                                    if (saldo_1 % 100 > 0)
                                    printf("cento ");
                                    else 
                                    printf("cem ");
                                }
                                if(aux_c == 2)
                                printf("duzent");
                                if(aux_c == 3)
                                printf("trezent");
                                if(aux_c == 4)
                                printf("quatrocent");
                                if(aux_c == 5)
                                printf("quinhent");
                                if(aux_c == 6)
                                printf("seiscent");
                                if(aux_c == 7)
                                printf("setecent");
                                if(aux_c == 8)
                                printf("oitocent");
                                if(aux_c == 9)
                                printf("novecent");
                                if (saldo_1 % 100 > 0)
                                printf("os e "); 
                                else
                                printf("as ");               
                            }
                            if((i == 3) && (aux_c > 0))
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
                                    if (saldo_1 % 10 > 0)
                                    printf("e ");
                                }
                            }
                            if(i == 4)
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

                    }
                    printf("(%d) nota(s) de R$1,00.\n", saldo_1);

                    break;
                case 4:
                    do
                    {
                        printf("\nMENU ABASTECER O CAIXA ELETRONICO\n");
                        printf("\n(450) Cedulas de 450");
                        printf("\n(250) Cedulas de 250");
                        printf("\n(50) Cedulas de 50");
                        printf("\n(20) Cedulas de 20");
                        printf("\n(10) Cedulas de 10");
                        printf("\n(5) Cedulas de 5");
                        printf("\n(2) Cedulas de 2");
                        printf("\n(1) Cedulas de 1");
                        printf("\n(0) Voltar ao menu gerente\n");
                        scanf("%d", &menuAbastecer);

                        switch (menuAbastecer)
                        {
                        case 450:
                            if (saldo_450 == 100)
                            {
                                printf("\nCapacidade maxima de notas de R$450,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (100 - saldo_450) * 450;
                                saldo_450 = 100;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 250:
                            if (saldo_250 == 200)
                            {
                                printf("\nCapacidade maxima de notas de R$250,00 alcançada.\n");
                            }
                            else{
                                vlr_saldo += (200 - saldo_250) * 250;
                                saldo_250 = 200;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 50:
                            if (saldo_50 == 400)
                            {
                                printf("\nCapacidade maxima de notas de R$50,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (400 - saldo_50) * 50;
                                saldo_50 = 400;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 20:
                            if (saldo_20 == 800)
                            {
                                printf("\nCapacidade maxima de notas de R$20,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (800 - saldo_20) * 20;
                                saldo_20 = 800;
                                
                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 10:
                            if (saldo_10 == 1600)
                            {
                                printf("\nCapacidade maxima de notas de R$10,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (1600 - saldo_10) * 10;
                                saldo_10 = 1600;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 5:
                            if (saldo_5 == 3200)
                            {
                                printf("\nCapacidade maxima de notas de R$5,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (3200 - saldo_5) * 5;
                                saldo_5 = 3200;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 2:
                            if (saldo_2 == 6400)
                            {
                                printf("\nCapacidade maxima de notas de R$2,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (6400 - saldo_2) * 2;
                                saldo_2 = 6400;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 1:
                            if (saldo_1 == 12800)
                            {
                                printf("\nCapacidade maxima de notas de R$1,00 alcançada.\n");
                            }
                            else
                            {
                                vlr_saldo += (12800 - saldo_1);
                                saldo_1 = 12800;

                                printf("\nOperacao realizada com sucesso.\n");
                            }
                            break;
                        case 0:
                            printf("\nVoce escolheu voltar ao menu gerente.\n");
                            break;
                        default:
                            printf("\nValor invalido. Tente novamente\n");
                            break;
                        }
                    } while (menuAbastecer != 0);
                    
                    break;
                case 5:
                    printf("\nVoce escolheu voltar ao menu principal.\n");
                    break;
                default:
                    printf("\nValor invalido. Tente novamente.\n");
                    break;
                }
            }while(menuGerente != 5);
            break;
        case 3://Finalizar
            printf("\nVoce escolheu finalizar.");
            break;
        default://Inválido
            printf("\nValor invalido. Tente novamente.\n");
            break;
        }
    }while(menuPrincipal != 3);

    return 0;
}