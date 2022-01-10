#include <stdio.h>
#ifndef _MOVIMENTACAO_H
#define _MOVIMENTACAO_H
#include <stdbool.h>

#define ARQ_MOVIMENTACAO "movimentacao.dat"

/* Estrutura que representa uma data */
typedef struct {
  char s[11];  //Armazena as datas
} data; 

/* Estrutura que representa uma movimentação */
typedef struct {
 int num_conta; // número da conta da movimentação
 float valor; //valor do saque ou deposito
 data dt_movimentacao; //chama a estrutura data
 int tipo; // 1–saque ou 2-depósito
} movimentacao; 

/* função que cadastra uma nova movimentação no arquivo */
void cadastrar_movimentacao(void);
/* função que lista todas as movimentações feitas em uma
 conta bancária em um período */
void listar_movimentacoes(void);

#endif


