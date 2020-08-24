#include "lista.h"

p_no inserirNaLista(p_no lista, char chave[50]){

    p_no novo = malloc(sizeof(No));
    /* copia a chave pro novo nó... */
    strncpy(novo->chave, chave, strlen(chave));
    /* ...e o ensere na lista */
    novo->proximo  = lista;
    lista = novo;

    return lista;
}

p_no destruirLista(p_no lista){

    p_no auxiliar = lista;
    /* enquanto houver nós, auxiliar libera memória e passa pro pŕoximo */
    while(auxiliar != NULL){

        lista = lista->proximo;
        free(auxiliar);
        auxiliar = lista;
    }

    return lista;
}