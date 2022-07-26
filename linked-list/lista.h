#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

typedef struct No{
	int endereco;
	int tamanho;
	struct No* proximo;
} No;

typedef struct Lista{
	No* inicio;
} Lista;

typedef No* p_No;
typedef Lista* p_Lista;

p_No criaNo(int endereco, int tamanho);

p_Lista criaLista(int s);

p_Lista insereNo(p_Lista lista, p_No novo);

p_Lista mesclaNos(p_Lista lista);

p_Lista removeZerados(p_Lista lista);

void imprime(p_Lista lista, int s);

void destroiLista(p_Lista lista);

#endif