#include "pilha.h"

void criaPilha(p_Pilha *pilha){

    *pilha = malloc(sizeof(Pilha));

    (*pilha)->tamanho = 0;
    (*pilha)->topo = NULL;
}

void empilha(p_Pilha pilha, int x){

    p_No novo = malloc(sizeof(No));

    novo->posicao = x;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    (pilha->tamanho)++;
}

int desempilha(p_Pilha pilha){

    p_No auxiliar = pilha->topo;
    int x = auxiliar->posicao;

    pilha->topo = pilha->topo->proximo;

    free(auxiliar);

    (pilha->tamanho)--;

    return x;
}

int buscaTopo(p_Pilha pilha){

    int x;

    if(pilha->topo == NULL)
        return -1;

    x = pilha->topo->posicao;

    return x;
}

void destroiPilha(p_Pilha pilha){

    p_No auxiliar = pilha->topo;

    while(auxiliar != NULL){

        pilha->topo = pilha->topo->proximo;
        free(auxiliar);
        auxiliar = pilha->topo;
    }
    free(pilha);
}