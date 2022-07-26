#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "pilha.h"

typedef struct No{
    char* nome;
    int distancia;
    struct No* esq;
    struct No* dir;
} No;

typedef No* p_No;

p_No criaNo(p_Pilha pilha);
p_No construirArvore(p_No no, p_Pilha pilha, int altura);
int temNoNaArvore(p_No no, char* procurado, int altura);
void imprimeArvorePre(p_No no, int altura);
p_No destroiArvore(p_No no);

#endif