#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include "lista.h"

typedef struct{
    int **adj;
    int m, n;
} Grafo;

typedef Grafo * p_grafo;

p_grafo criar_grafo(int m, int n);
int     tem_aresta();
void    define_matriz_adj(p_grafo grafo, int** mapa, int m, int n, int h);
void    destroi_grafo(p_grafo g);

#endif