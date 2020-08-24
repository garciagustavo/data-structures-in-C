#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include <stdio.h>
#include <malloc.h>

typedef struct {
    int id, clock, prioridade, dependencia;
} Processo;

typedef struct {
    Processo *processo;
    int n, tamanho;
} FP;

typedef Processo* p_processo;
typedef FP* p_fp;

p_fp criar_filaprio(int tamanho);
void insere(p_fp fprio , Processo processo);
Processo extrai_maximo(p_fp fprio);
int vazia(p_fp fprio);
int cheia(p_fp fprio);
void destroir_fila(p_fp fprio);

#endif
/*#############################################3*/

void insere(p_fp fprio , Item item){
    fprio ->v[fprio ->n] = item;
    fprio ->n++;
    sobe_no_heap(fprio , fprio ->n - 1);
}

#define PAI(i) ((i-1) /2)

void sobe_no_heap(p_fp fprio , int k){
    if (k > 0 && fprio ->v[PAI(k)]. chave < fprio ->v[k]. chave) {
        troca (&fprio ->v[k], &fprio ->v[PAI(k)]);
        sobe_no_heap(fprio , PAI(k));
    }
}

Item extrai_maximo(p_fp fprio){
    Item item = fprio ->v[0];
    troca (&fprio ->v[0], &fprio ->v[fprio ->n - 1]);
    fprio ->n--;
    desce_no_heap(fprio , 0);
    return item;
}

#define F_ESQ(i) (2*i+1) /* Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /* Filho direito de i*/

void desce_no_heap(p_fp fprio , int k){
    int maior_filho;
    if (F_ESQ(k) < fprio ->n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio ->n &&
            fprio ->v[F_ESQ(k)]. chave < fprio ->v[F_DIR(k)]. chave)
        maior_filho = F_DIR(k);
        if (fprio ->v[k]. chave < fprio ->v[maior_filho ]. chave) {
            troca (&fprio ->v[k], &fprio ->v[maior_filho ]);
            desce_no_heap(fprio , maior_filho);
        }
    }
}