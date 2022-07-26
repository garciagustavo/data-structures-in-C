#ifndef LISTA_H
#define LISTA_H

#include <malloc.h>

typedef struct No{
    int m, n;
    struct No *proximo;
} No;

typedef No* p_no;

p_no inserir_lista(p_no lista, int m, int n);
p_no destroi_lista(p_no lista);

#endif