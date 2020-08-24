#include "abb.h"

p_no criaNo(char livro[80]){
    /* aloca memória pro nó e inicializa seus campos,... */
    p_no no = malloc(sizeof(No));
    no->dir = NULL;
    no->esq = NULL;
    /* ...inclusive o nome do livro */
    strcpy(no->livro, livro);

    return no;
}

p_no adicionar(p_no no, char livro[80]){

    p_no novo;
    /* instala o nó quando chegar na posição de folha */
    if(no == NULL){
        
        novo = criaNo(livro);
        return novo;
    }
    /* caso contrário, continua procurando uma posição adequada */
    if(strcmp(livro, no->livro) < 0)
        no->esq = adicionar(no->esq, livro);
    else
        no->dir = adicionar(no->dir, livro);
    
    return no;
}

void removerSucessor(p_no no){

    p_no t = no->dir;
    p_no pai = no;

    while(t->esq != NULL){

        pai = t;
        t = t->esq;
    }
    
    if(pai->esq == t)
        pai->esq = t->dir;
    else
        pai->dir = t->dir;

    strcpy(no->livro, t->livro);
    free(t);
}

p_no remover(p_no no, char livro[80]){

    p_no auxiliar;

    if(no == NULL)
        return NULL;
    /* procura o nó a ser removido */
    if(strcmp(livro, no->livro) < 0)
        no->esq = remover(no->esq, livro);
    else if(strcmp(livro, no->livro) > 0)
        no->dir = remover(no->dir, livro);
    /* desaloca o nó e devolve sua folha direita */
    else if (no->esq == NULL){

        auxiliar = no->dir;
        free(no);
        return auxiliar;
    }
    /* ou desaloca o nó e devolve sua folha esquerda */
    else if (no->dir == NULL){

        auxiliar = no->esq;
        free(no);
        return auxiliar;
    }
    /* senão remove o sucessor */
    else
        removerSucessor(no);

    return no;
}

void imprimirEmOrdem(p_no no, char prefixo[80]){
/* a impressão em ordem condicionada imprime na ordem lexicográfica correta */
    if(no != NULL){

        imprimirEmOrdem(no->esq, prefixo);
        if(strncmp(prefixo, no->livro, strlen(prefixo)) == 0)
            printf("%s\n", no->livro);
        imprimirEmOrdem(no->dir, prefixo);
    }

}

void destruirABB(p_no no){

    if(no != NULL){

        destruirABB(no->esq);
        destruirABB(no->dir);
        free(no);
    }
}