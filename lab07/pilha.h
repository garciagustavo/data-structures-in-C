#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct no_pilha{
    char nome[20];
    struct no_pilha* proximo;
} no_pilha;

typedef struct Pilha{
    int tamanho;
    no_pilha* topo;
} Pilha;

typedef Pilha* p_Pilha;

p_Pilha criaPilha();
void empilha(p_Pilha pilha, char nome[20]);
char* desempilha(p_Pilha pilha);
void destroiPilha(p_Pilha pilha);

#endif