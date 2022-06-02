#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    long long cpf, pot;
    int aux_a, aux_b, cont;
    int pd, sd, soma_pd, soma_sd;
    int vld_pd, vld_sd, x;
    int verdadeiro = 1;


    while (verdadeiro)
    {    
        printf("Insira o CPF: ");
        scanf("%lld", &cpf);
        pot = 10;
        cont = 0;
        soma_pd = 0;
        soma_sd = 0;
        printf("\n%lld", cpf);

        for (int i = 0; i < 11; i++)
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
                cont++;
            }

            pot*=10;
            aux_b = aux_a;
        }
        vld_pd = ((soma_pd * 10) % 11) % 10;
        vld_sd = ((soma_sd * 10) % 11) % 10;
        x = cpf / (pot / 10);

        if ((vld_pd != pd) || (vld_sd != sd) || (cont == 10) || (cpf <= 0) || (cpf / (pot / 10) > 0))
        printf("\nCPF invalido!\n");
        else
        break;
    }
        printf("\n%i",x);
    printf("\nCPF valido!");

    return 0;
}
