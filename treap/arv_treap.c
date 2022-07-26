#include "arv_treap.h"

p_No criarNo(int id, double valor, int prioridade){

    p_No no = malloc(sizeof(No));

    no->id         = id;
    no->valor      = valor;
    no->prioridade = prioridade;
    no->quantidade = 1;
    no->dir        = NULL;
    no->esq        = NULL;

    return no;
}

p_No rotacionaParaEsquerda(p_No no){

    p_No x = no->dir;
    
    no->dir = x->esq;
    x->esq  = no;
    
    return x;
}

p_No rotacionaParaDireita(p_No no){

    p_No x = no->esq;

    no->esq = x->dir;
    x->dir  = no;
    
    return x;
}

p_No buscaNaTreap(p_No no, int id){
    /* devolve "nulo", ou o nó encontrado */
    if (no == NULL || no->id == id)
       return no;
     
    if (no->id < id) /* chave maior que a id, busca na direita */
       return buscaNaTreap(no->dir, id);
    /* senão, busca na esquerda */
    return buscaNaTreap(no->esq, id);
}

p_No insereNaTreap(p_No no, int id, double valor, int prioridade){

    if(no == NULL) /* cria e devolve o nó q será inserido */
        return criarNo(id, valor, prioridade);
 
    if(id <= no->id){ /* respeita a ABB de acordo com o valor */

        no->esq = insereNaTreap(no->esq, id, valor, prioridade);
 
        if (no->esq->prioridade > no->prioridade) /* respeita a Treap de acordo com a Id */
            no = rotacionaParaDireita(no);
    } /* o mesmo vale pro lado direito */
    else{

        no->dir = insereNaTreap(no->dir, id, valor, prioridade);
 
        if(no->dir->prioridade > no->prioridade)
            no = rotacionaParaEsquerda(no);
    }
    return no;
}

void imprimirEmOrdem(p_No no, double tarifa){

    if(no != NULL){

        imprimirEmOrdem(no->esq, tarifa);
        printf("Banco %d R$ %.2f Tarifa R$ %.2f\n", no->id, no->valor, (no->quantidade*tarifa));
        imprimirEmOrdem(no->dir, tarifa);
    }
}

void destruirTreap(p_No no){

    if(no != NULL){

        destruirTreap(no->esq);
        destruirTreap(no->dir);
        free(no);
    }
}