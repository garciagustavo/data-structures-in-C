#include "fila.h"
#include <malloc.h>

p_Fila inicializarFila(){

    p_Fila fila;
    fila = malloc(sizeof(Fila));
    fila->partida_num   = 1;
    fila->num_jogadores = 0;
    fila->inicio        = NULL;
    fila->fim           = NULL;

    return fila;
}

p_No criarNo(int h, int indice){

    p_No novo = malloc(sizeof(No));

    novo->indice     = indice;
    novo->habInicial = h;
    novo->habilidade = h;
    novo->proximo    = NULL;

    return novo;
}

void enfileirar(p_Fila fila, p_No novo){

    if(fila->inicio == NULL)
        fila->inicio = novo;
    else
        fila->fim->proximo = novo;

    fila->fim = novo;

    (fila->num_jogadores)++;
}

p_No desenfileirar(p_Fila fila){

    p_No primeiro = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL)
        fila->fim = NULL;

    primeiro->proximo = NULL;

    (fila->num_jogadores)--;

    return primeiro;
}

void destruirFila(p_Fila fila){
/* no final, a fila possui apenas 1 elemento, apontado por fila->inicio */
    free(fila->inicio);
    free(fila);
}
/*##################################################################################*/

p_Fila inscricoes(p_Fila torneio, int n){

    int i, h, indice=1;
    p_No novo;

    for(i=0; i<n; i++){
        /* enfileira todos os participantes iniciais */
        scanf(" %d", &h);
        novo = criarNo(h, indice);
        enfileirar(torneio, novo);
        indice++;
    }

    return torneio;
}

void imprimeResultado(int partida_num, int vencedor, int perdedor, char operacao){
    /* vencedor significa o índice do vencedor, assim como perdedor */
    switch(operacao){
        /* caso seja uma partida do torneio */
        case '1': 
            
            if(vencedor < perdedor)
                printf("Partida %d: %d vs %d venceu %d\n",
                    partida_num, vencedor, perdedor, vencedor);
            else
                printf("Partida %d: %d vs %d venceu %d\n",
                    partida_num, perdedor, vencedor, vencedor);
            break;
        /* caso seja uma partida da repescagem */
        case '2':

            if(vencedor < perdedor)
                printf("Partida %d da repescagem: %d vs %d venceu %d\n",
                    partida_num, vencedor, perdedor, vencedor);
            else
                printf("Partida %d da repescagem: %d vs %d venceu %d\n",
                    partida_num, perdedor, vencedor, vencedor);
            break;
        /* caso seja uma partida da final */
        case '3': 

            if(vencedor < perdedor)
                printf("Final do torneio: %d vs %d campeao %d\n",
                    vencedor, perdedor, vencedor);
            else
                printf("Final do torneio: %d vs %d campeao %d\n",
                    perdedor, vencedor, vencedor);
            break;
    }
}

void atualizaHabilidade(p_No vencedor, p_No perdedor, int k){

    if(((vencedor->habilidade - perdedor->habilidade) + k) < vencedor->habInicial)
        vencedor->habilidade = (vencedor->habilidade - perdedor->habilidade) + k;
    else
        vencedor->habilidade = vencedor->habInicial;

    if(((perdedor->habilidade / 2) + k) < perdedor->habInicial)
        perdedor->habilidade = (perdedor->habilidade / 2) + k;
    else
        perdedor->habilidade = perdedor->habInicial;
}

void TORNEIO_FINAL(p_Fila torneio, p_Fila repescagem){

    p_No jogador1 = torneio->inicio;
    p_No jogador2 = repescagem->inicio;

    jogador1->habilidade = jogador1->habInicial;
    jogador2->habilidade = jogador2->habInicial;

    if(jogador1->habilidade > jogador2->habilidade){

        imprimeResultado(torneio->partida_num, jogador1->indice, jogador2->indice, '3');
    }
    else{

        imprimeResultado(torneio->partida_num, jogador2->indice, jogador1->indice, '3');
    }
}

void TORNEIO(p_Fila torneio, p_Fila repescagem, int k){

    int j, num_jogadores=torneio->num_jogadores;
    p_No jogador1, jogador2;

    for(j=0; j<(num_jogadores/2); j++){

        jogador1 = torneio->inicio;
        jogador2 = torneio->inicio->proximo;

        if(jogador1->habilidade == jogador2->habilidade){

            if(jogador1->indice < jogador2->indice){

                imprimeResultado(torneio->partida_num, jogador1->indice, jogador2->indice, '1');

                atualizaHabilidade(jogador1, jogador2, k);
                
                enfileirar(torneio, desenfileirar(torneio));
                enfileirar(repescagem, desenfileirar(torneio));
            }
            else if(jogador1->indice > jogador2->indice){

                imprimeResultado(torneio->partida_num, jogador2->indice, jogador1->indice, '1');

                atualizaHabilidade(jogador2, jogador1, k);

                enfileirar(repescagem, desenfileirar(torneio));
                enfileirar(torneio, desenfileirar(torneio));
            }
        }
        else if(jogador1->habilidade > jogador2->habilidade){

            imprimeResultado(torneio->partida_num, jogador1->indice, jogador2->indice, '1');

            atualizaHabilidade(jogador1, jogador2, k);
            
            enfileirar(torneio, desenfileirar(torneio));
            enfileirar(repescagem, desenfileirar(torneio));
        }
        else if(jogador1->habilidade < jogador2->habilidade){

            imprimeResultado(torneio->partida_num, jogador2->indice, jogador1->indice, '1');

            atualizaHabilidade(jogador2, jogador1, k);

            enfileirar(repescagem, desenfileirar(torneio));
            enfileirar(torneio, desenfileirar(torneio));
        }
        
        (torneio->partida_num)++;
    }
}

void REPESCAGEM(p_Fila repescagem, int k){

    int j, num_jogadores=repescagem->num_jogadores;
    p_No jogador1, jogador2;

    for(j=0; j<(num_jogadores/2); j++){

        jogador1 = repescagem->inicio;
        jogador2 = repescagem->inicio->proximo;

        if(jogador1->habilidade == jogador2->habilidade){

            if(jogador1->indice < jogador2->indice){

                imprimeResultado(repescagem->partida_num, jogador1->indice, jogador2->indice, '2');

                atualizaHabilidade(jogador1, jogador2, k);

                enfileirar(repescagem, desenfileirar(repescagem));
                free(desenfileirar(repescagem));
            }
            else if(jogador1->indice > jogador2->indice){

                imprimeResultado(repescagem->partida_num, jogador2->indice, jogador1->indice, '2');

                atualizaHabilidade(jogador2, jogador1, k);

                free(desenfileirar(repescagem));
                enfileirar(repescagem, desenfileirar(repescagem));
            }
        }
        else if(jogador1->habilidade > jogador2->habilidade){

            imprimeResultado(repescagem->partida_num, jogador1->indice, jogador2->indice, '2');

            atualizaHabilidade(jogador1, jogador2, k);

            enfileirar(repescagem, desenfileirar(repescagem));
            free(desenfileirar(repescagem));
        }
        else if(jogador1->habilidade < jogador2->habilidade){

            imprimeResultado(repescagem->partida_num, jogador2->indice, jogador1->indice, '2');

            atualizaHabilidade(jogador2, jogador1, k);

            free(desenfileirar(repescagem));
            enfileirar(repescagem, desenfileirar(repescagem));
        }

        (repescagem->partida_num)++;
    }

}