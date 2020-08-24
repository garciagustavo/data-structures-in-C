#include "fila_prioridade.h"

p_fp criar_filaprio(int tamanho){
    
    p_fp fprio = malloc(sizeof(FP));
    
    fprio->processo     = malloc(tamanho*sizeof(Processo));
    fprio->processados  = malloc(tamanho*sizeof(int));
    fprio->n            = 0;
    fprio->tamanho      = tamanho;
    
    return fprio;
}

void insere(p_fp fprio , Processo processo){

    fprio->processo[fprio->n] = processo;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n-1);
}

#define PAI(i) ((i-1)/2) /* Pai de i*/

void sobe_no_heap(p_fp fprio, int k){
    if (k>0 && fprio->processo[PAI(k)].prioridade < fprio->processo[k].prioridade){
        troca (&fprio->processo[k], &fprio->processo[PAI(k)]);
        sobe_no_heap(fprio , PAI(k));
    }
    else if(k>0 && fprio->processo[PAI(k)].prioridade == fprio->processo[k].prioridade){

        if(fprio->processo[PAI(k)].id > fprio->processo[k].id)
    }
}

Processo extrai_maximo(p_fp fprio){
    
    Processo processo = fprio->processo[0];
    troca (&fprio->processo[0], &fprio->processo[fprio->n-1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return processo;
}

#define F_ESQ(i) (2*i+1) /* Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /* Filho direito de i*/

void desce_no_heap(p_fp fprio, int k){
    int maior_filho;
    if (F_ESQ(k) < fprio->n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
            fprio->processo[F_ESQ(k)].prioridade < fprio->processo[F_DIR(k)].prioridade)
            maior_filho = F_DIR(k);
        if (fprio->processo[k].prioridade < fprio->processo[maior_filho].prioridade){
            troca (&fprio->processo[k], &fprio->processo[maior_filho]);
            desce_no_heap(fprio , maior_filho);
        }
    }
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

void troca(p_processo processoA, p_processo processoB){

    Processo auxiliar;

    auxiliar   = *processoA;
    *processoA = *processoB;
    *processoB = auxiliar;
}

void destroi_fila(p_fp fprio){

    free(fprio->processo);
    free(fprio);
}



