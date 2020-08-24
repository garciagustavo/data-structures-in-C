#include "memoria.h"

int main(void){

    int n, s, i, endereco, tamanho;
    char operacao;
    p_Lista lista;

    scanf("%d %d", &n, &s);

    lista = criaLista(s);

    for(i=0; i<n; i++){

        scanf(" %c", &operacao);

        switch(operacao){

            case 'A': scanf("%d", &tamanho); lista = aloca(lista, tamanho); break;
            case 'D': scanf("%d %d", &endereco, &tamanho); lista = desaloca(lista, endereco, tamanho); break;
            case 'R': lista = realoca(lista); break;
            case 'P': imprime(lista, s); break;
        }
    }

    destroiLista(lista);

    return 0;
}
