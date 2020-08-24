#include <math.h>
#include "fila.h"

int main(void){

    int n, k, i;
    p_Fila torneio, repescagem;

    scanf("%d %d", &n, &k);

    torneio    = inicializarFila();
    repescagem = inicializarFila();
    /* são realizadas as incrições dos participantes enfileirando todos na fila torneio */
    torneio = inscricoes(torneio, pow(2, n));

    for(i=0; i<(n+1); i++){

        if(torneio->inicio->proximo == NULL && repescagem->inicio->proximo == NULL){

            TORNEIO_FINAL(torneio, repescagem);
        }
        else{

            TORNEIO(torneio, repescagem, k);
            
            REPESCAGEM(repescagem, k);

            if(torneio->inicio->proximo == NULL)
                while(repescagem->inicio->proximo != NULL){

                    REPESCAGEM(repescagem, k);
                }
        }
    }

    destruirFila(torneio);
    destruirFila(repescagem);

    return 0;
}