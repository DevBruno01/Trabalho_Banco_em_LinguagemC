#include <stdio.h>
#ifndef _MOVIMENTACAO_H
#define _MOVIMENTACAO_H
#include <stdbool.h>

#define ARQ_MOVIMENTACAO "movimentacao.dat"

/* Estrutura que representa uma data */
typedef struct {
  char s[11];  //Armazena as datas
} data; 

/* Estrutura que representa uma movimenta��o */
typedef struct {
 int num_conta; // n�mero da conta da movimenta��o
 float valor; //valor do saque ou deposito
 data dt_movimentacao; //chama a estrutura data
 int tipo; // 1�saque ou 2-dep�sito
} movimentacao; 

/* fun��o que cadastra uma nova movimenta��o no arquivo */
void cadastrar_movimentacao(void);
/* fun��o que lista todas as movimenta��es feitas em uma
 conta banc�ria em um per�odo */
void listar_movimentacoes(void);

#endif


