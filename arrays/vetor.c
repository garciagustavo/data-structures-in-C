#include "vetor.h"
#include <malloc.h>

p_Tabela criarTabela(void){

	p_Tabela tabela = malloc(sizeof(Tabela));
	tabela->ordens  = malloc(sizeof(Ordem));

	tabela->n       = 0;
	tabela->alocado = 1;
	tabela->prox_id = 1;
/* colocar -1 nas posições da ordem, por segurança */
	tabela->ordens[0].id    = -1;
	tabela->ordens[0].quant = -1;
	tabela->ordens[0].preco = -1;

	return tabela;
}

void destruirTabela(p_Tabela tabela){

	free(tabela->ordens);
	free(tabela);
}

void dobraVetor(p_Tabela tabela){

	int i;
	p_Ordem temp;
	/* um ponteiro temporário segura o vetor de ordens */
	temp = tabela->ordens;
		/* dobra o tamanho do vetor original de ordens */
		tabela->alocado *= 2;
		tabela->ordens  = malloc(tabela->alocado * sizeof(Ordem));
		/* transfere os valores do temporário pro novo vetor de tamanho dobrado */
		for(i=0; i<tabela->n; i++)
			tabela->ordens[i] = temp[i];
		free(temp);
		/* por segurança, coloca -1 em todas as posições do vetor que não são usadas */
		for(i=tabela->n; i<(tabela->alocado - tabela->n); i++){
			tabela->ordens[i].id    = -1;
			tabela->ordens[i].quant = -1;
			tabela->ordens[i].preco = -1;
		}
}

void adicionarOrdem(p_Tabela tabela, Ordem ordem){
	/* se o vetor está cheio, dobra o seu tamanho */
	if(tabela->n == tabela->alocado)
		dobraVetor(tabela);
	/* preenche a nova ordem na posição n do vetor */
	tabela->ordens[tabela->n].id    = ordem.id;
	tabela->ordens[tabela->n].quant = ordem.quant;
	tabela->ordens[tabela->n].preco = ordem.preco;

	(tabela->n)++;
}

void executarOrdem(p_Tabela contraria, p_Tabela corrente, char cv){

	Ordem temp;
	int i, k=0, match=0;
	/* completa a ordem nova temp */
	temp.id = contraria->prox_id;
	scanf("%d %lf", &temp.quant, &temp.preco);
		/* compara a ordem nova com todas as ordens da tabela contrária */
		for(i=0; i<contraria->n; i++){
			/* se houve match com alguma ordem, inicia-se a transação */
			if(temp.preco == contraria->ordens[i].preco && temp.quant > 0){
				/* é vendida a quantidade necessária */
				while(temp.quant > 0 && contraria->ordens[i].quant > 0){

					(temp.quant)--;
					(contraria->ordens[i].quant)--;

					k++;
				}
				/* se a ordem de compra ou de venda zerou, confirma a venda */
				if(temp.quant == 0 || contraria->ordens[i].quant == 0){

					if(cv == 'C')
						printf("ordem %d vende para ordem %d a quantidade %d por %.2f\n",
						contraria->ordens[i].id,
						temp.id,						
						k,
						contraria->ordens[i].preco);

					else if(cv == 'V')
						printf("ordem %d vende para ordem %d a quantidade %d por %.2f\n",
						temp.id,
						contraria->ordens[i].id,
						k,
						contraria->ordens[i].preco);
				}
				/* se ambas as ordens zerarem, remove e zera (-1) as ordens */
				if(contraria->ordens[i].quant == 0 && temp.quant == 0){

					if(temp.id > contraria->ordens[i].id){
						removerOrdem(contraria, i, contraria->ordens[i].id);
						printf("ordem %d concluida\n", temp.id);
					}
					else if(temp.id < contraria->ordens[i].id){
						printf("ordem %d concluida\n", temp.id);
						removerOrdem(contraria, i, contraria->ordens[i].id);
					}
					
					temp.id    = -1;
					temp.quant = -1;
					temp.preco = -1;

					i--; k=0;
				}
				else{
					
					if(temp.quant == 0){

						printf("ordem %d concluida\n", temp.id);

						temp.id    = -1;
						temp.quant = -1;
						temp.preco = -1;

						k=0;
					}
					else if(contraria->ordens[i].quant == 0){

						removerOrdem(contraria, i, contraria->ordens[i].id);

						i--; k=0;
					}				
				}

				match = 1;
			}
		}
		/* se a ordem nova não teve match, ou teve mas sobrou moedas,
		ela é adicionada a sua respectiva tabela */
		if(match == 0)
			adicionarOrdem(corrente, temp);
		if(match == 1 && temp.quant > 0)
			adicionarOrdem(corrente, temp);
}

void removerOrdem(p_Tabela tabela, int i, int id){
	
	p_Ordem temp;
/* remove a ordem, rearranja o vetor e coloca -1 nas posições removidas */
	for(; i<(tabela->n)-1; i++)
		tabela->ordens[i] = tabela->ordens[i+1];

	tabela->ordens[i].id    = -1;
	tabela->ordens[i].quant = -1;
	tabela->ordens[i].preco = -1;

	(tabela->n)--;

	printf("ordem %d concluida\n", id);
/* diminui o tamanho do vetor pela metade, caso seu espaço usado seja um quarto de seu tamanho */
	if(tabela->alocado == 4 * tabela->n){

		temp = tabela->ordens;

		tabela->alocado /= 2;
		tabela->ordens  = malloc(tabela->alocado * sizeof(Ordem));

		for(i=0; i<tabela->n; i++)
			tabela->ordens[i] = temp[i];
		free(temp);
	}
}