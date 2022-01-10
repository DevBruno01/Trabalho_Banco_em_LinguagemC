/*Nome do integrante: 
Bruno Brocanelli
Ads Manh�*/
#include <stdio.h>
#include <stdlib.h>
/*Inclus�o de blibliotecas/arquivos feitas para serem utilizados no programa,
conta.ce .h conta contem a forma que ser� trabalhada o cadastro e a listagem de uma conta,
ja movimentacao.c e .h contem as formas de movimenta��o.*/
#include "conta.h"
#include "conta.c"
#include "movimentacao.h"
#include "movimentacao.c"

int main()
{
	/*menu de op��es para o usuario escolher entre cadastrar, listar, fazer uma movimeta��o e lista.*/
    int op;
    do {
        printf("\nBem vindo ao Banco\n");
        printf("<0> Sair do programa\n");
        printf("<1> Cadastrar uma conta\n");
        printf("<2> Listar as contas\n");
        printf("<3> Realizar uma movimentacao\n");
        printf("<4> Listar movimentacoes\n");
        printf("Opcao: ");
        scanf("%d", &op);
        
        /*switch feito para chamar cada fun��o, ap�s o fim da fun��o sim do switch.*/
        switch (op)
        {
        	case 0:
        		system("cls");
        		printf("Finalizando Programa!!!");
                break;
            case 1:
                cadastrar_conta();
                break;
            case 2:
                listar_contas();
                break;
           case 3: cadastrar_movimentacao();
				break;    
			case 4:
				listar_movimentacoes();
				break;		
            default:
                printf("\nErro: opcao invalida!\nDigite novamente\n");
                break;
        }
    } while (op != 0);
    return 0;
}
