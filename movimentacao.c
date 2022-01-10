#include <stdio.h>
#include <stdlib.h>
//Inclusão de arquivos para a realização das movimentações.
#include "movimentacao.h"
#include "conta.h"

//Iniciação das funções wue irão interagir com as bibliotecas/arquivos
void cadastrar_movimentacao()
{
	system("cls");
	
	/*Abertura de arquivos, para registro de uma movimentação do tipo saque ou deposito*/
	FILE *arq;
	arq = fopen(ARQ_CONTA, "r+b");
	if(arq == NULL)
	{
		printf("\nErro ao abrir arquivo ARQ_CONTA\n");
		system("pause");
		exit(1);
	}
	
	FILE *f;
	f = fopen(ARQ_MOVIMENTACAO, "ab");
	if(f == NULL)
	{
		printf("\nErro ao abrir arquivo AQR_Movimentacao\n");
		system("pause");
		exit(1);
	}
	
	//Inicialização de variaveis.
	movimentacao m;
	conta c;
	int num_conta;
	
	printf("\nRealizar uma movimentacao\n");
	printf("Numero da conta: ");
	scanf("%d", &num_conta);
	m.num_conta = num_conta;
	
	//Funçoes reposnsaveis por procurar e ler uma variavel do arquivo arq.
	fseek(arq, (num_conta-1) * sizeof(conta),SEEK_SET);
	fread(&c, sizeof(conta), 1, arq);
	
	//Verifica o fim de arquivo.
	if(feof(arq))
    {
		fprintf(stderr, "\nErro: numero da conta invalido!\n");
	}
	else
	{
		//Exibe o nome do cliente.
		printf("Nome do cliente: %s\n",c.nome);
		//O usuario ira escolher 1- para saque 2-para deposito.
		printf("1-Para saque\n2-para deposito\nOpcao: ");
		scanf("%d", &m.tipo);
		
		switch(m.tipo)
		{
			case 1:
				//Solicita ao usuario a data e o valor do saque.
				printf("Digite a data: ");
				scanf(" %s", m.dt_movimentacao.s);
				printf("Valor do saque: R$: ");
				scanf("%f", &m.valor);
				
				//Se valor for menor ou igual a zero entra na condição.
				if(m.valor <= 0)
				{
					system("cls");
					printf("Nao eh permitido realizar saques menores ou iguais a zero!\n");
					fclose(arq);
					return;
				}
				
				//Se saldo for menor que o valor para saque entra na condição.
				if(c.saldo <= m.valor)
				{
					system("cls");
					printf("\nNao eh possivel fazer a transacao, a conta nao possui saldo\n");
					fclose(arq);
					return;
    			}
	
					c.saldo -= m.valor;
					
					printf("Saldo atual: R$ %.2f", c.saldo); 
					
					//Procura a posição no arquivo arq, escreve a informação nos arquivos arq e f.
					fseek(arq, (num_conta-1)*sizeof(conta), SEEK_SET);
					fwrite(&c, sizeof(conta), 1, arq);
					fwrite(&m, sizeof(movimentacao), 1, f);
	
					printf("\nSaque realizado com sucesso\n");break;
			
			case 2:
				//Solicita ao usuario a data e o valor do saque.
					printf("Digite a data: ");
					scanf(" %s", m.dt_movimentacao.s);
					printf("Valor do deposito: R$: ");
					scanf("%f", &m.valor);
					
					//Se o valor for menor ou igual a zero entra na condição.
					if(m.valor <= 0)
					{
						system("cls");
						printf("Nao eh permitido realizar depositos menores ou iguais a zero!\n");
						fclose(arq);
						return;
					}
	
					c.saldo += m.valor;
	
					printf("Saldo atual: R$ %.2f", c.saldo); 
	
					////Procura a posição no arquivo arq, escreve a informação nos arquivos arq e f.
					fseek(arq, (num_conta-1)*sizeof(conta), SEEK_SET);
					fwrite(&c, sizeof(conta), 1, arq);
					fwrite(&m, sizeof(movimentacao), 1, f);
	
					printf("\nDeposito realizado com sucesso\n");break;
					
			default:
				printf("Opção não existente!!!\nDigite Novamente\n");
				break;
		}
		
		//Fechamento dos arquivos.
	fclose(arq);
	fclose(f);
}

}
	
void listar_movimentacoes()
{
	system("cls");
	
	//Abertura do arquivo, para listar as movimentações.
	
	FILE *f;
	f = fopen(ARQ_MOVIMENTACAO, "r");
	if(f == NULL)
	{
		printf("\nErro ao abrir arquivo\n");
		system("pause");
		exit(1);
	}
	
	//Inicialização das Variaveis.
	movimentacao m;
	int num_conta;
	
	//Solicita o numero da conta para ser realizada a busca das movimentações realizadas da conta.
	printf("Digite o numero da conta: ");
	scanf("%d", &num_conta);
	
	printf("\n\tMovimentacoes realizadas\n");
    printf("-------------------------------------------------\n");
    printf("#Conta       valor saque/deposito      data \n");
    printf("-------------------------------------------------\n");

	//Função que ira ler as informações do arquivo e apresentar ao usuario.
    while (fread(&m, sizeof(movimentacao), 1, f) > 0)
	{
		if(m.num_conta == num_conta){
			printf("%06d \t\t    %0.2f  \t    %s\n", m.num_conta, m.valor, m.dt_movimentacao.s);
		}
    }
    printf("-------------------------------------------------\n");
	
	//Fechamento de arquivo.	
	fclose(f);
	return;
}		

	
