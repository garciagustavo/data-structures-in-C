#ifndef VETOR_H
#define VETOR_H

#include <stdio.h>

typedef struct ordem{
	int id;
	int quant;
	double preco;
} Ordem;

typedef struct tabela{
	Ordem *ordens;
	int n;
	int alocado;
	int prox_id;
}Tabela;

typedef Tabela * p_Tabela;

typedef Ordem * p_Ordem;

p_Tabela criarTabela(void);

void destruirTabela(p_Tabela tabela);

void adicionarOrdem(p_Tabela tabela, Ordem ordem);

void executarOrdem(p_Tabela contraria, p_Tabela corrente, char cv);

void removerOrdem(p_Tabela tabela, int i, int id);

#endif