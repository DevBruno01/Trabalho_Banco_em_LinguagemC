#include <stdio.h>
#include "conta.h"

/*Arquivo que contem a construção das funções, suas nomeações se encomtram no aqruivo de final .h*/

void cadastrar_conta()
{
	system("cls");
	/*Abertura do arquivo que serão armazenadas as informações do cliente*/
    FILE * arq;
    if ((arq = fopen(ARQ_CONTA, "ab")) == NULL) {
        fprintf(stderr, "\nErro: não foi possivel abrir o arquivo %s!\n", ARQ_CONTA);
        return;
    }
    //Inicialização de Variavel
	conta c;
    printf("\n\nNova Conta\n");
    
    fseek(arq, 0, SEEK_END);
    //Inicio do cadastro atraves de estruturas  e funçoes dos arquivos
    c.num_conta = ftell(arq) / sizeof(conta) + 1;
    printf("Numero da conta: %d\n", c.num_conta);
    printf("Nome do cliente: ");
    scanf(" %50[^\n]", c.nome);
    printf("Saldo da conta.: R$ ");
    scanf("%f", &c.saldo);
    //Escreve a informação no arquivo
    fwrite(&c, sizeof(conta), 1, arq);
    //Fecha o arquivo
    fclose(arq);
    printf("\nConta cadastrada com sucesso!\n");
}

void listar_contas()
{
	system("cls");
	//Abertura de arquivo.
    FILE * arq;
    if ((arq = fopen(ARQ_CONTA, "r")) == NULL) {
        fprintf(stderr, "\nErro: nao ha' nenhuma conta cadastrada!\n");
        return;
    }
    //Inicialização de variavel.
    conta c;
    //Inicio da listagem atraves de estruturas e funçoes de arquivos.
    printf("\n\tContas Cadastradas\n");
    printf("--------------------------------------------\n");
    printf("#Conta Nome do Cliente             Saldo\n");
    printf("--------------------------------------------\n");
    //Busca as informações no arquivo.
    while (fread(&c, sizeof(conta), 1, arq) > 0) {
    	//Exibe as informações
        printf("%06d %-25.25s %0.2f\n", c.num_conta, c.nome, c.saldo);
    }
    printf("--------------------------------------------\n");
    fclose(arq);
}
