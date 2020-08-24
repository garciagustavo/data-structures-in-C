#include "arv_treap.h"

int main(void){

    int n, i, j, prioridade;
    double k, r;
    p_No registro=NULL, auxiliar;

    /*
    n = número de tranferências no registro
    k = valor da tarifa por transferência
    i = identificador do baco
    r = valor a ser transferido na transação
    */

    srand(time(NULL));

    scanf("%d %lf", &n, &k);

    for(j=0; j<n; j++){

        scanf(" %d %lf", &i, &r);

        prioridade = rand();

        auxiliar = buscaNaTreap(registro, i);

        /* se já existe um registro com aquela ID, o valor desse é incrementado
           com o valor a ser inserido, e não é criado um novo nó.
           Caso não existe um registro com essa ID, um novo nó é inserido na árvore */
        if(auxiliar == NULL)
            registro = insereNaTreap(registro, i, r, prioridade);
        else{

            auxiliar->valor = auxiliar->valor + r;
            auxiliar->quantidade++;
        }
    }

    imprimirEmOrdem(registro, k);

    destruirTreap(registro);

    return 0;
}