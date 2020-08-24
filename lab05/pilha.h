#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <malloc.h>

typedef struct No{
    int posicao;
    struct No* proximo;
} No;

typedef No* p_No;

typedef struct{
	int tamanho;
    p_No topo;
} Pilha;

typedef Pilha* p_Pilha;
typedef Pilha** pp_Pilha;

void criaPilha(p_Pilha *pilha);
void empilha(p_Pilha pilha, int x);
int desempilha(p_Pilha pilha);
int buscaTopo(p_Pilha pilha);
void destroiPilha(p_Pilha pilha);

#endif