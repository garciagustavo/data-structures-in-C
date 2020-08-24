#include "vetor.h"

int main(){
/* Cria as tabelas de negociação de compra e venda */
	char cv;
	p_Tabela BUY, SELL;

	BUY  = criarTabela();
	SELL = criarTabela();

	scanf("%c", &cv);
/* Entra com a ordem de compra ou venda, executa-a ou adiciona-a na respectiva tabela */
	while(cv != '#'){

		if(cv == 'C')
			executarOrdem(SELL, BUY, cv);

		if(cv == 'V')
			executarOrdem(BUY, SELL, cv);
		
		/* prepara as tabelas para as próximas inserções */
		(BUY->prox_id)++;
		(SELL->prox_id)++;

		scanf(" %c", &cv);
	}
/* desaloca as tabelas após as execuções */
	destruirTabela(BUY);
	destruirTabela(SELL);

	return 0;
}