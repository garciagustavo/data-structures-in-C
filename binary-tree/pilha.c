#include "pilha.h"

p_Pilha criaPilha(){

    p_Pilha pilha = malloc(sizeof(Pilha));

    pilha->tamanho = 0;
    pilha->topo = NULL;

    return pilha;
}
void empilha(p_Pilha pilha, char nome[20]){

    no_pilha* novo = malloc(sizeof(no_pilha));

    strcpy(novo->nome, nome);
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    (pilha->tamanho)++;
}
char* desempilha(p_Pilha pilha){

    no_pilha* auxiliar = pilha->topo;
    char* nome = malloc(20*sizeof(char));

    strcpy(nome, auxiliar->nome);

    pilha->topo = pilha->topo->proximo;

    free(auxiliar);

    (pilha->tamanho)--;

    return nome;
}
void destroiPilha(p_Pilha pilha){

    no_pilha* auxiliar = pilha->topo;

    while(auxiliar != NULL){

        pilha->topo = pilha->topo->proximo;
        free(auxiliar);
        auxiliar = pilha->topo;
    }
    free(pilha);
}