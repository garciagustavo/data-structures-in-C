#include "lista.h"
#include <malloc.h>

/*######################################################################*/

p_No criaNo(int endereco, int tamanho){

    p_No novo = malloc(sizeof(No));

    novo->endereco = endereco;
    novo->tamanho  = tamanho;
    novo->proximo  = NULL;

    return novo;
}
/*######################################################################*/

p_Lista criaLista(int s){
    /* aloca memória pra lista */
    p_Lista lista = malloc(sizeof(Lista));
    /* cria um nó vazio no começo da lista pra facilitar as operações */
    lista->inicio = criaNo(-1, -1);
    /* cria nó com o tamanho todo da lista desalocado */
    lista->inicio->proximo = criaNo(0, s);

    return lista;
}
/*######################################################################*/

p_Lista insereNo(p_Lista lista, p_No novo){

    p_No anterior = lista->inicio;
    p_No auxiliar = lista->inicio->proximo;

    if(auxiliar == NULL){

        lista->inicio->proximo = novo;

        return lista;
    }

    while(auxiliar != NULL){
        /* insere nó no final da lista */
        if((novo->endereco > auxiliar->endereco) && auxiliar->proximo == NULL){

            auxiliar->proximo = novo;

            return lista;
        }
        /* insere nó no meio da lista */
        else if(novo->endereco < auxiliar->endereco){

            anterior->proximo = novo;
            novo->proximo = auxiliar;

            return lista;
		}

        anterior = anterior->proximo;
        auxiliar = auxiliar->proximo;
    }

    return lista;
}
/*######################################################################*/

p_Lista mesclaNos(p_Lista lista){

    p_No temp;
    p_No anterior = lista->inicio->proximo;
    p_No auxiliar = anterior->proximo;

    while(auxiliar != NULL){
        /* coloca o tamanho de 2 nós em um, e remove o segundo */
        if(auxiliar->endereco == (anterior->endereco + anterior->tamanho)){

            anterior->tamanho += auxiliar->tamanho;

            temp = auxiliar;

            anterior->proximo = auxiliar->proximo;

            free(temp);
        }

        anterior = anterior->proximo;
        auxiliar = auxiliar->proximo;
    }

    return lista;
}
/*######################################################################*/

p_Lista removeZerados(p_Lista lista){

    p_No temp;
    p_No anterior = lista->inicio;
    p_No auxiliar = lista->inicio->proximo;

    while(auxiliar != NULL){
        /* remove o nó com tamanho 0 */
        if(auxiliar->tamanho == 0){

            temp = auxiliar;

            anterior->proximo = auxiliar->proximo;

            free(temp);

            return lista;
        }

        anterior = anterior->proximo;
        auxiliar = auxiliar->proximo;
    }

    return lista;
}
/*######################################################################*/

void imprime(p_Lista lista, int s){

    p_No auxiliar = lista->inicio->proximo;

    printf("Segmentos livres da heap:\n");

    while(auxiliar != NULL){
        /* sai da função caso não haja nós para serem impressos */
        if(auxiliar->endereco == 0 && auxiliar->tamanho == s)
            break;

        printf("(%d, %d)\n", auxiliar->endereco, auxiliar->tamanho);

        auxiliar = auxiliar->proximo;
    }
}
/*######################################################################*/

void destroiLista(p_Lista lista){

    p_No auxiliar = lista->inicio;

    while(auxiliar != NULL){

        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
        auxiliar = lista->inicio;
    }

    free(lista);
}