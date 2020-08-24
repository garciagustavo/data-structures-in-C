#include "lista.h"

p_no inserir_lista(p_no lista, int m, int n){

    p_no novo = malloc(sizeof(No));
    
    novo->m = m;
    novo->n = n;
    
    novo->proximo = lista;

    return novo;
}

p_no destroi_lista(p_no lista){

    p_no auxiliar = lista;
    /* enquanto houver nós, auxiliar libera memória e passa pro pŕoximo */
    while(auxiliar != NULL){

        lista = lista->proximo;
        free(auxiliar);
        auxiliar = lista;
    }

    return lista;
}