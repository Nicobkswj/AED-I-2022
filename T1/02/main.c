//Folha de Pagamentos
//Alunos: Nicolas Rocha, Kauan Henrik, Igor Nunes, Lucas Rodrigues, Gabriel Azevedo & Luiz Felipe Silva.

#include <stdio.h>
#include <stdlib.h>

int main () {
    int numFuncionarios, j , i;

    printf ("Digite o numero de funcionarios: ");
    scanf ("%d" , &numFuncionarios);

    while(numFuncionarios < 1 || numFuncionarios > 10000){     //Fazendo a verificação do número de funcionários
        printf("Voce digitou um numero de funcionarios invalido! \n");
        scanf ("%d" , &numFuncionarios);
    }

    int matricula, verdadeiro = 1;
    for(i = 1; i<=numFuncionarios; i++){
        int salario = 0;
        while(verdadeiro){
            printf("Digite a matricula do funcionario %d: ", i);
            scanf("%d", &matricula);

            if(matricula < 1 || matricula > 30000)     //Fazendo a verificação da matrícula
                printf("Matricula invalida. Tente novamente.\n");
            else
                break;
        }
        for(j = 1; j<=matricula; j++){
            if(matricula % j == 0)
                salario += j;    //Somando um divisor da matrí­cula ao salário
        }
            printf("O salario do funcionario %d devera ser de %d\n\n", i, salario);
    }

    printf("-----FIM-----");

    return 0;
}
