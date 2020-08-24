#ifndef FILA_H
#define FILA_H

#include <stdio.h>

typedef struct No{
    int indice;
	int habInicial;
	int habilidade;
	struct No* proximo;
} No;

typedef No* p_No;

typedef struct{
	int partida_num;
	int num_jogadores;
	p_No inicio, fim;
} Fila;

typedef Fila* p_Fila;

p_Fila inicializarFila();
p_No criarNo(int h, int indice);
void enfileirar(p_Fila fila, p_No novo);
p_No desenfileirar(p_Fila fila);
void destruirFila(p_Fila fila);
/*############################################################*/
p_Fila inscricoes(p_Fila torneio, int n);
void imprimeResultado(int partida_num, int vencedor, int perdedor, char operacao);
void atualizaHabilidade(p_No vencedor, p_No perdedor, int k);
void TORNEIO_FINAL(p_Fila torneio, p_Fila repescagem);
void TORNEIO(p_Fila torneio, p_Fila repescagem, int k);
void REPESCAGEM(p_Fila repescagem, int k);

#endif