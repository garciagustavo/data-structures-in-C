#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include <stdio.h>
#include <malloc.h>

typedef struct {
    int id, clock, prioridade, dependencia;
} Processo;

typedef struct {
    Processo *processo;
    int* processados;
    int n, tamanho;
} FP;

typedef Processo* p_processo;
typedef FP* p_fp;

p_fp criar_filaprio(int tamanho);
void insere(p_fp fprio , Processo processo);
void sobe_no_heap(p_fp fprio, int k);
Processo extrai_maximo(p_fp fprio);
void desce_no_heap(p_fp fprio, int k);
int vazia(p_fp fprio);
int cheia(p_fp fprio);
void troca(p_processo processoA, p_processo processoB);
void destroi_fila(p_fp fprio);

#endif