#include "fila_prioridade.h"

p_fp criar_filaprio(int tamanho){
    
    p_fp fprio = malloc(sizeof(FP));
    
    fprio->processo = malloc(tamanho * sizeof(Processo));
    fprio->n        = 0;
    fprio->tamanho  = tamanho;

    inicializar_fila(fprio, tamanho);        
    
    return fprio;
}

void insere(p_fp fprio, Processo processo){
    
    fprio->processo[fprio->n] = processo;
    fprio->n++;
}

Processo extrai_maximo(p_fp fprio){
    
    int j, max = 0;
    Processo auxiliar;
    
    for(j = 1; j < fprio->n; j++)
        if(fprio->processo[max].prioridade < fprio->processo[j].prioridade)
            max = j;
    
    auxiliar = fprio->processo[max];

    troca(&(fprio->processo[max]), &(fprio->processo[fprio->n-1]));

    inicializar_processo(&(fprio->processo[fprio->n-1]));

    fprio->n--;
    
    return auxiliar;
}

int vazia(p_fp fprio){

    if(fprio->n == 0)
        return 1;
    else
        return 0;
}

int cheia(p_fp fprio){

    if(fprio->n == fprio->tamanho)
        return 1;
    else
        return 0;
}

void destroir_fila(p_fp fprio){

    free(fprio->processo);
    free(fprio);
}



