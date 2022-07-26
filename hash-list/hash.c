#include "hash.h"

p_hash criar_hash(){

    int i;
    p_hash tabela = malloc(sizeof(Hash));

    /* coloca NULL em todas as posições do vetor */
    for(i=0; i<MAX; i++)
        tabela->vetor[i] = NULL;

    return tabela;
}

int hash(char *chave){

    int i, n=0;

    /* calcula o hash */
    for(i=0; i < strlen(chave); i++)
        n = (256 * n + chave[i]) % MAX;

    return n;
}

void inserir(p_hash tabela, char *chave) {
    /* calcula o hash correspondente a chave... */
    int n = hash(chave); 
    /* e guarda a chave nessa posição */
    tabela->vetor[n] = inserirNaLista(tabela->vetor[n], chave);
}

int buscar(p_hash tabela, char *chave){

    int k = hash(chave);
    p_no auxiliar = tabela->vetor[k];

    /* começa a busca na lista correspondente, caso a posição do vetor tenha alguma chave */
    while(auxiliar != NULL){
    
        if(strcmp(auxiliar->chave, chave) == 0)
            return 1;
        else
            auxiliar = auxiliar->proximo;
    }

    return 0;
}

void destruir_hash(p_hash tabela){

    int i;

    for(i=0; i < MAX; i++){
        /* as posições nulas são puladas */
        if(tabela->vetor[i] != NULL)
            tabela->vetor[i] = destruirLista(tabela->vetor[i]);
    }

    free(tabela);
}