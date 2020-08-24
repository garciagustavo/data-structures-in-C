#include "arv_binaria.h"

p_No criaNo(p_Pilha pilha){

    p_No no       = malloc(sizeof(No));
    no->nome      = desempilha(pilha);
    no->distancia = -1;
    no->dir       = NULL;
    no->esq       = NULL;

    return no;
}

p_No construirArvore(p_No no, p_Pilha pilha, int altura){

    no = criaNo(pilha);

    if(altura == 1)
        return no;

    if(no->dir == NULL && altura > 1)
        no->dir = construirArvore(no->dir, pilha, altura -1);
    if(no->esq == NULL && altura > 1)
        no->esq = construirArvore(no->esq, pilha, altura -1);

    if(no->esq != NULL && no->dir != NULL){

        return no;
    }

    return NULL;
}

int temNoNaArvore(p_No no, char* procurado, int distancia){

    int x=0;

    if(no == NULL)
        return 0;

    if(strcmp(no->nome, procurado) == 0){

        no->distancia = distancia;
        return 1;
    }

    x = temNoNaArvore(no->esq, procurado, distancia +1);
    if(x != 0)
        return x;

    return temNoNaArvore(no->dir, procurado, distancia +1);
}

void imprimeArvorePre(p_No no, int altura){

    if(no != NULL){

        if(no->distancia != -1)
            printf("%s %d ", no->nome, no->distancia);
        imprimeArvorePre(no->esq, altura -1);
        imprimeArvorePre(no->dir, altura -1);
    }
}

p_No destroiArvore(p_No no){

    if(no != NULL){

        destroiArvore(no->esq);
        destroiArvore(no->dir);
        free(no->nome);
        free(no);
    }

    return NULL;
}