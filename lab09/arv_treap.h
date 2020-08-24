#ifndef ARV_TREAP_H
#define ARV_TREAP_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
    int id;
    int prioridade;
    int quantidade;
    double valor;
    struct No *esq, *dir;
} No;

typedef No* p_No;

p_No criarNo(int id, double valor, int prioridade);
p_No rotacionaParaEsquerda(p_No no);
p_No rotacionaParaDireita(p_No no);
p_No buscaNaTreap(p_No no, int id);
p_No insereNaTreap(p_No no, int id, double valor, int prioridade);
void imprimirEmOrdem(p_No no, double tarifa);
void destruirTreap(p_No no);

#endif