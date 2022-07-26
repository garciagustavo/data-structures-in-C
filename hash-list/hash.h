#ifndef HASH_H
#define HASH_H

#define MAX 1783

#include <stdio.h>
#include "lista.h"

typedef struct{
    p_no vetor[MAX];
} Hash;

typedef Hash* p_hash;

p_hash criar_hash();
int  hash(char *chave);
void inserir(p_hash tabela, char *chave);
int  buscar(p_hash tabela, char *chave);
void destruir_hash(p_hash tabela);

#endif