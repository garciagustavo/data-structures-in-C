#ifndef LISTA_H
#define LISTA_H

#include <string.h>
#include <malloc.h>

typedef struct No{
    char chave [50];
    struct No *proximo;
} No;

typedef No* p_no;

p_no inserirNaLista(p_no lista, char chave[50]);
p_no destruirLista(p_no lista);

#endif