#ifndef ABB_H
#define ABB_H

#include <string.h>
#include <malloc.h>
#include <stdio.h>

typedef struct No{
    char livro[80];
    struct No *esq, *dir;
} No;

typedef No * p_no;

p_no criarNo(char livro[80]);
p_no adicionar(p_no no, char livro[80]);
void removerSucessor(p_no no);
p_no remover(p_no no, char livro[80]);
void imprimirEmOrdem(p_no no, char prefixo[80]);
void destruirABB(p_no no);

#endif