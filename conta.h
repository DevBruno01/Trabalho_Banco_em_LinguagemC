
#include <stdio.h>
/*Arquivo .h no qual apenas deixamos as estruturas que serão utilizadas no arquivo.c*/

#ifndef _CONTA_H 
#define _CONTA_H 

#define ARQ_CONTA "contas.dat"

/*Inciação de estruturas*/
typedef struct { 
   int num_conta; 
   char nome[51]; 
   float saldo; 
} conta; 

/*Função que deve cadastro o cliente, deve gerar um numero de ID automatico*/
void cadastrar_conta(void); 
/*Função que deve listar as contas cadastradas juntamente com seus saldos*/
void listar_contas(void); 

#endif
