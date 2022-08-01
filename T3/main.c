#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

char ccClientes[50][10], cpfClientes[50][15];
int saqueClientes[50][999], qtdSaques[50], totalClientes[50];

int menuPrincipal, menuCliente, menuRelatorios;
int qtdClientes = 0;

int vlrSaldo = 188600, saqueTotal = 0; 
int saqueNotas[8], notas[8]= {450, 250, 50, 20, 10, 5, 2, 1}, saldoNotas[8] = {100, 200, 400, 800, 1600, 3200, 6400, 12800};


int main() {

    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    void incluirCliente(), mostrarCliente(), alterarCliente(), excluirCliente(),
        sacar_dinheiro(), valores_sacados(), valor_saldo_existente(), qtd_cedulas_existentes();
    int i;

    for (i = 0; i < 50; i++)
    {
        qtdSaques[i] = 0;    
        totalClientes[i] = 0;
    }

    do {
        printf("\n\nMENU PRINCIPAL - Digite a opcao desejada abaixo: ");
        printf("\n(1) Cliente");
        printf("\n(2) Saque");
        printf("\n(3) Relatorios");
        printf("\n(4) Finalizar\n");
        scanf("\n%d",&menuPrincipal );
        switch (menuPrincipal)
        {
        case 1:
            do {
                printf("\n\nMENU CLIENTE - Digite a opcao desejada abaixo: ");
                printf("\n(1) Incluir");
                printf("\n(2) Mostrar");
                printf("\n(3) Alterar");
                printf("\n(4) Excluir");
                printf("\n(5) Voltar\n");
                scanf("\n%d",&menuCliente);
                switch (menuCliente)
                {
                case 1:
                    incluirCliente();
                    break;
                case 2:
                    mostrarCliente();
                    break;
                case 3:
                    alterarCliente();
                    break;
                case 4:
                    excluirCliente();
                    break;
                case 5:
                    printf("\nVoltando ao menu principal...\n");
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente : \n");
                    break;
                }
            } while (menuCliente != 5);
            break;
        case 2:
            printf("\nVoce escolheu a opcao saque.\n");
            sacar_dinheiro();
            break;
        case 3:
            do {
                printf("\n\nMENU RELATORIOS - Digite a opcao desejada abaixo: ");
                printf("\n(1) Valores sacados");
                printf("\n(2) Valor do saldo existente");
                printf("\n(3) Quantidade de cédulas existentes");
                printf("\n(4) Voltar\n");
                scanf("\n%d",&menuRelatorios);
                switch (menuRelatorios)
                {
                case 1:
                    valores_sacados();
                    break;
                case 2:
                    valor_saldo_existente();
                    break;
                case 3:
                    qtd_cedulas_existentes();
                    break;
                case 5:
                    printf("\nVoltando ao menu principal...\n");
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente : \n");
                    break;
                }
            } while (menuRelatorios != 4);
            break;
        case 4:
            printf("\nVoce escolheu a opcao Finalizar.");
            printf("\nObrigado por usar nossos serviços!");
            printf("\n-----------------------------------------------------------\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente : \n");
            break;
        }
    } while(menuPrincipal != 4);

    return 0;
}
//objetivo: fazer a inclusão de um novo cliente no cadastro
//parametros: nenhum
//retorno: nenhum
void incluirCliente()
{
    void geraContaCorrente(char c[]), gera_cpf_valido(char c[]);
    char cpfTest[15], ccTest[10], permissao;
    int i;

    if (qtdClientes < 50)
    {
        printf("\n-----------------------------------------------------------\n");
        printf("\nNúmero do cliente: %d", qtdClientes+1);
        geraContaCorrente(ccTest);
        gera_cpf_valido(cpfTest);
        printf("\n-----------------------------------------------------------\n");
        printf("\nDeseja concluir o cadastro?(S/N)");
        scanf(" %s", &permissao);
        switch (permissao)
        {
        case 's':
        case 'S':
            printf("\nCadastro concluído.");
            for (i = 0; i < 10; i++)
                ccClientes[qtdClientes][i] = ccTest[i]; 
            for (i = 0; i < 15; i++)
                cpfClientes[qtdClientes][i] = cpfTest[i];
            
            qtdClientes++;
            break;
        case 'n':
        case 'N':
            printf("\nCadastro cancelado.");
            break;
        default:
            printf("\nOpção inválida. Cadastro cancelado.");
            break;
        }
    }
    else
    printf("\nQuantidade máxima de cliente cadastrados alcançada.");
}
//objetivo: apresentar os dados dos clientes cadastrados no sistema
//parametros: nenhum
//retorno: nenhum
void mostrarCliente()
{
    int i;
    for (i = 0; i < qtdClientes; i++)
    {
        printf("\n-----------------------------------------------------------\n");
        printf("\nNúmero do cliente: %d", i+1);
        printf("\nConta corrente: %s", ccClientes[i]);
        printf("\nCpf: %s\n", cpfClientes[i]);
        printf("\n-----------------------------------------------------------\n");
    }
}
//objetivo: fazer uma alteração no cpf ou número da conta corrente
//parametros: nenhum
//retorno: nenhum
void alterarCliente()
{
    int pedir_conta_corrente(char c[]), verifica_cc_valida(char c[]), verifica_cpf_valido(char cpf[]);
    char ccAlterada[10], ccNova[10], cpfNovo[15];
    int clienteAlterado, cOUcpf, i, j, existente, cont;

    clienteAlterado = pedir_conta_corrente(ccAlterada);

    if (ccAlterada[0] != 'v')
    {
        if (qtdSaques[clienteAlterado] > 0)
            printf("\nA alteração não pode ser realizada, pois este cliente já realizou saques."); 
        else
        {
            do
            {   
                printf("\nEscolha uma das opções abaixo: ");
                printf("\n(1) Alterar conta corrente");
                printf("\n(2) Alterar cpf");
                printf("\n(3) Voltar ao menu\n");
                scanf("%d", &cOUcpf);

                switch (cOUcpf)
                {
                case 1:
                    do
                    {
                        printf("\nInforme o novo valor da conta corrente (use o formato 999.999-X) ou digite 'v' para voltar ao menu: \n");
                        scanf(" %10s", &ccNova);
                        
                        existente = 0;
                        if (ccNova[0] == 'v')
                        {
                            break;
                        }
                        if (verifica_cc_valida(ccNova) == 1)
                        {
                            for ( i = 0; i < qtdClientes; i++)
                            {
                                cont = 0;
                                for (j = 0; j < 10; j++)
                                {
                                    if (ccClientes[i][j] == ccNova[j])
                                        cont++;
                                }
                                if (cont == 10)
                                    existente = 1;
                            }            
                            if (existente == 1)
                            printf("\nConta corrente já cadastrada. Tente novamente: ");
                        }
                        else
                            printf("\nFormato inválido. Tente novamente: ");
                        
                    } while ((verifica_cc_valida(ccNova) == 0) || (existente == 1));
                    
                    if (ccNova[0] != 'v')
                    {
                        for (i = 0; i < 10; i++)
                            ccClientes[clienteAlterado][i] = ccNova[i];
                        printf("\nAlteração realizada.\n");
                    }

                    break;
                case 2:
                    do
                    {
                        printf("\nInforme o novo valor do cpf (use o formato 999.999.999-99) ou digite 'v' para voltar ao menu: \n");
                        scanf(" %15s", &cpfNovo);
                        
                        existente = 0;
                        if (cpfNovo[0] == 'v')
                            break;
                        if (verifica_cpf_valido(cpfNovo) == 1)
                        {
                            for ( i = 0; i < qtdClientes; i++)
                            {
                                cont = 0;
                                for (j = 0; j < 15; j++)
                                {
                                    if (cpfClientes[i][j] == cpfNovo[j])
                                        cont++;
                                }
                                if (cont == 15)
                                    existente = 1;
                            }            
                            if (existente == 1)
                            printf("\nCPF já cadastrado. Tente novamente: ");
                        }
                        else
                            printf("\nFormato inválido. Tente novamente: ");
                        
                    } while ((verifica_cpf_valido(cpfNovo) == 0) || (existente == 1));
                    
                    if (cpfNovo[0] != 'v')
                    {
                        for (i = 0; i < 15; i++)
                            cpfClientes[clienteAlterado][i] = cpfNovo[i];
                        printf("\nAlteração realizada.\n");
                    }
                    break;

                case 3:
                    printf("\nVoltando ao menu...\n");
                    break;

                default:
                    printf("\nOpção inválida. Tente novamente.\n");
                    break;
                }
            } while (cOUcpf != 3);
        }
    }
    else
        printf("\nVoltando ao menu...\n");
    

}
//objetivo: apagar um cliente do cadastro
//parametros: nenhum
//retorno: nenhum
void excluirCliente()
{
    int pedir_conta_corrente(char c[]);
    char ccExcluida[10];
    int clienteExcluido, i, j;

    clienteExcluido = pedir_conta_corrente(ccExcluida);

    if (ccExcluida[0] != 'v')
    {
        if (qtdSaques[clienteExcluido] > 0)
            printf("\nA exclusão não pode ser realizada, pois este cliente já realizou saques."); 
        else
        {
            qtdClientes--;
            if (clienteExcluido != 0)
            {
                for (i = clienteExcluido; i < qtdClientes; i++)
                {
                    for (j = 0; j < 10; j++)
                        ccClientes[i][j] = ccClientes[i+1][j];

                    for (j = 0; j < 15; j++)
                        cpfClientes[i][j] = cpfClientes[i+1][j];
                }
            }
            else
            {
                for (i = 0; i < 10; i++)
                    ccClientes[qtdClientes][i] = '\0';
                for (i = 0; i < 15; i++)
                    cpfClientes[qtdClientes][i] = '\0';
            }
            printf("\nExclusão realizada.\n");
        }
    }
    else
        printf("\nVoltando ao menu...\n");
    
}
//objetivo: imprimir a quantidade de cada cédula liberada e o valor do saque
//parametros: nenhum
//retorno: nenhum
void sacar_dinheiro()
{
    void escrever_valor_extenso(int valor);
    int pedir_conta_corrente(char c[]);
    char ccSaque[10];
    int vlrSaque, auxSaque, i, clienteSaque;

    clienteSaque = pedir_conta_corrente(ccSaque);

    switch (ccSaque[0])
    {
    case 'v':
        printf("\nVoltando ao menu...\n");
        break;
    
    default:
        printf("\nInforme o valor do saque: ");
        scanf("%d", &vlrSaque);
        
        while (vlrSaque <= 0)
        {
            printf("\nO valor do saque deve ser positivo. Tente novamente: ");
            scanf("%d", &vlrSaque);
        }

        if (vlrSaque > vlrSaldo)
        {
            printf("Notas no caixa insuficientes para realizar este saque. \n");
            break;
        }
        
        saqueClientes[clienteSaque][qtdSaques[clienteSaque]] = vlrSaque;
        auxSaque = vlrSaque;
        saqueTotal += vlrSaque;
        totalClientes[clienteSaque] += vlrSaque;
        qtdSaques[clienteSaque]++;

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
        
        printf("\nValor sacado: R$%d,00 ou ", vlrSaque);
        escrever_valor_extenso(vlrSaque);
        if (vlrSaque <= 1)
        printf("real.\n");
        else
        printf("reais.\n");

        break;
    }

}
void valores_sacados()
{
    void escrever_valor_extenso(int valor);
    int i, j;

    printf("\n-----------------------------------------------------------\n");
    printf("\nRelatório 'Valores sacados'\n");
    printf("\n-----------------------------------------------------------\n");
    for (i = 0; i < qtdClientes; i++)
    {
        printf("\nNúmero do cliente: %d", i+1);
        printf("\nConta corrente: %s", ccClientes[i]);
        printf("\nCpf: %s", cpfClientes[i]);
        if (qtdSaques[i] == 0)
            printf("\nEste cliente não realizou nenhum saque.\n");
        else
        {
            for (j = 0; j < qtdSaques[i]; j++)
            {
                printf("\nSaque %d: R$%d,00", j+1, saqueClientes[i][j]);
            }            
            printf("\nSaque total do cliente: R$%d,00\n", totalClientes[i]);
        }
        printf("\n-----------------------------------------------------------\n");
    }
    printf("\nSaque total: R$%d,00 (", saqueTotal);
    escrever_valor_extenso(saqueTotal);
    if (saqueTotal <= 1)
    printf("real)\n");
    else
    printf("reais)\n");
    printf("\n-----------------------------------------------------------\n");

}
void valor_saldo_existente()
{
    void escrever_valor_extenso(int valor);

    printf("\n-----------------------------------------------------------\n");
    printf("\nRelatório 'Valor do saldo existente'\n");
    printf("\n-----------------------------------------------------------\n");
    printf("\nR$%d,00 (", vlrSaldo);
    escrever_valor_extenso(vlrSaldo);
    if (vlrSaldo <= 1)
    printf("real)\n");
    else
    printf("reais)\n");
    printf("\n-----------------------------------------------------------\n");

}
void qtd_cedulas_existentes()
{
    void escrever_valor_extenso(int valor);
    int vlrCedula[8], i;

    for (i = 0; i < 8; i++)
        vlrCedula[i] = saldoNotas[i] * notas[i];
    

    printf("\n-----------------------------------------------------------\n");
    printf("\nRelatório 'Valor do saldo existente'\n");
    printf("\n-----------------------------------------------------------\n");
    for (i = 0; i < 8; i++)
    {
        printf("\n%d de R$%d,00 ( ", saldoNotas[i], notas[i]);
        escrever_valor_extenso(saldoNotas[i]);
        printf(")\n");
    }
    printf("\n-----------------------------------------------------------\n");

}
//objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
//parametros: cpf onde sera armazenado o cpf valido
//retorno: nenhum
void gera_cpf_valido(char cpf[])
{
    //funções
    char geraNumero();
    int verifica_cpf_valido(char cpf[]);
    void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[]);
    //variáveis
    char cpfValido[12], cpfPontuacao[15];
    int i;
    int j, cont = 0; 

    for (i = 0; i < 9; i++)
    {
        cpfValido[i] = geraNumero();
    }

    do
    {   
        if (j % 10 == 0)
        {
            cpfValido[9] = cont + '0';
            cont++;
            j = 0;
        }
        cpfValido[10] = j + '0';
        j++;
        cpfValido[11] = '\0';

        //printf("\n%s", cpfValido);
        insere_pontuacao_cpf(cpfValido, cpfPontuacao);
        
    } while (verifica_cpf_valido(cpfPontuacao) != 1);


    for (i = 0; i < 15; i++)
    {
        cpf[i] = cpfPontuacao[i];
    }
    
    printf("\nCPF: %s\n", cpfPontuacao);

}
//objetivo:verifica se um cpf no formato 999.999.999-99 e valido
//parametros: cpf a ser verificado
//retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    void remove_pontuacao_cpf(char cpf_origem[], char cpf_destino[]);
    int valido = 1, i;
    long long cpfInt, pot = 10;
    char cpfValidando[12], cpfPontuacao[15];
    for (i = 0; i < 15; i++)
        cpfPontuacao[i] = cpf[i];
    remove_pontuacao_cpf(cpfPontuacao, cpfValidando);
    cpfInt = atoll(cpfValidando);
    int aux_a, aux_b, cont = 0;
    int pd, sd, soma_pd = 0, soma_sd = 0;
    int vld_pd, vld_sd;
    
    for (i = 0; i < 11; i++)
    {
        aux_a = (cpfInt % pot) / (pot / 10);

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

    if ((vld_pd != pd) || (vld_sd != sd) || (cont == 10) || (cpfInt <= 0) || (cpfInt / (pot / 10) > 0))
    valido = 0;
    
    if ((cpfPontuacao[3] != '.') || (cpfPontuacao[7] != '.') || (cpfPontuacao[11] != '-'))
    valido = 0;

    return(valido);
}
//objetivo:insere pontuacoes '.' e '- ' em um cpf
//parametros: cpf_origem o cpf recebido no format 99999999999
//            cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
//retorno: nenhum
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{

    int i;

    for (i = 0; i < 12; i++)
    {
        if (i <=2)
            cpf_destino[i] = cpf_origem[i];
        else if (i <=5)
            cpf_destino[i + 1] = cpf_origem[i];
        else if (i <= 8)
            cpf_destino[i + 2] = cpf_origem[i];
        else
            cpf_destino[i + 3] = cpf_origem[i];
    }   
    
    cpf_destino[3] = '.';
    cpf_destino[7] = '.';
    cpf_destino[11] = '-';

}
//objetivo:remove pontuacoes '.' e '- ' em um cpf
//parametros: cpf_origem o cpf com as pontuacoes inseridas no formato 999.999.999-99
//            cpf_destino o cpf recebido no format 99999999999
//retorno: nenhum
void remove_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{

    int i;

    for (i = 0; i < 12; i++)
    {
        if (i <=2)
            cpf_destino[i] = cpf_origem[i];
        else if (i <= 5)
            cpf_destino[i] = cpf_origem[i + 1];
        else if (i <= 8)
            cpf_destino[i] = cpf_origem[i + 2];
        else
            cpf_destino[i] = cpf_origem[i + 3];
    } 

}
//objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
//parametros: c onde armazera a conta gerada
//retorno:nenhum
void geraContaCorrente(char c[])
{

    char geraNumero(), geraAlfabeto();

    int i = 0;
    char contaCorrente[10];
    for(i = 0; i < 7; i++)
    {
        if(i != 3)
        {
            contaCorrente[i] = geraNumero();
        }
        else if(i == 3)
        {
            contaCorrente[i] = '.';
        }
    }
    contaCorrente[i] = '-';
    contaCorrente[i + 1] = geraAlfabeto();

    for(int i=0; i<10; i++)
    {
        c[i] = contaCorrente[i];
    }

    printf("\nCONTA CORRENTE: %s",contaCorrente);
}
//objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
//parametros: nenhum
//retorno:a letra do alfabeto
char geraAlfabeto()
{
    int i;
    char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    i=rand()%26;
    return(letras[i]-32);
}
//objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}
//objetivo: pedir para o usuário informar uma conta corrente válida
//parametros: conta corrente onde sera armazenada
//retorno: cliente pedido pelo usuário
int pedir_conta_corrente(char c[])
{
    int verifica_cc_valida(char c[]);
    char ccInformada[10];
    int i, j, cont, cliente, existente = 0;

    do
    {
        printf("\nInforme a conta corrente (use o formato 999.999-X) ou digite 'v' para voltar ao menu: \n");
        scanf(" %10s", &ccInformada);
        
        if (ccInformada[0] == 'v')
            break;
        if (verifica_cc_valida(ccInformada) == 0)
            printf("\nFormato inválido. Tente novamente: ");
        else
        {
            for ( i = 0; i < qtdClientes; i++)
            {
                cont = 0;
                for (j = 0; j < 10; j++)
                {
                    if (ccClientes[i][j] == ccInformada[j])
                        cont++;
                }
                if (cont == 10)
                {
                    existente = 1;
                    cliente = i;
                }
            }            
            if (existente == 0)
            printf("\nConta corrente não cadastrada. Tente novamente: ");
        }        
    } while ((verifica_cc_valida(ccInformada) == 0) && (ccInformada[0] != 'v') || (existente == 0));
    
    if (ccInformada[0] != 'v')
    {
        for (i = 0; i < 10; i++)
        {
            c[i] = ccInformada[i];
        }        
        return (cliente);
    }
    else
    {
        c[0] = ccInformada[0];
        return 0;
    }

}
//objetivo:verifica se uma conta corrente no formato 999.999-X e valido
//parametros: conta corrente a ser verificada
//retorno: 1 se e valido ou 0 se nao e valido
int verifica_cc_valida(char c[]){

    char ccVerificando[10], letras[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i, j, cont, valido = 1, ehLetra = 0, ehNumero;

    for (i = 0; i < 10; i++)
        ccVerificando[i] = c[i];

    for (i = 0; i < sizeof(letras); i++)
    {
        if (ccVerificando[8] == letras[i])
            ehLetra = 1;
    }    

    if (ehLetra == 0)
        valido = 0;
    else if ((ccVerificando[3] != '.') || (ccVerificando[7] != '-'))
        valido = 0;
    else
    {
        for (i = 0; i < 7; i++)
        {
            ehNumero = 0;
            for (j = 0; j < 10; j++)
            {
                if (i == 3)
                    i++;
                if (ccVerificando[i] == j)
                    ehNumero = 1;
            }
            if (ehNumero = 0)
                valido = 0;         
        }
    }

    return valido;

}
//objetivo: escrever um valor por extenso
//parametros: valor a ser convertido
//retorno: nenhum
void escrever_valor_extenso(int valor)
{
    int vlr, pot, aux, condicao = 0, i;
    int vlrVetor[6];

    vlr = valor;

    if(vlr == 0){
        printf("zero ");
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

}