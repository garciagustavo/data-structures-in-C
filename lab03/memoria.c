#include "memoria.h"

/*######################################################################*/

p_Lista aloca(p_Lista lista, int tamanho){

    p_No auxiliar = lista->inicio->proximo;

    while(auxiliar != NULL){

        if(auxiliar->tamanho >= tamanho){
            /* aloca memória diminuindo tamanho do nó de desalocação para a direita */
            auxiliar->tamanho  -= tamanho;
            auxiliar->endereco += tamanho;
            /* remove os nós com tamanho 0 */
            lista = removeZerados(lista);

            return lista;
        }

        auxiliar = auxiliar->proximo;
    }

    return lista;
}
/*######################################################################*/

p_Lista desaloca(p_Lista lista, int endereco, int tamanho){

    p_No novo;
    /* cria o novo nó de memória desalocada */
    novo = criaNo(endereco, tamanho);
    /* insere o novo nó em seu respectivo lugar na lista */
    lista = insereNo(lista, novo);
    /* mescla nós imediatamente vizinhos */
    /* a função passa duas vezes, uma pra cada lado do nó */
    lista = mesclaNos(lista);
    lista = mesclaNos(lista);

    return lista;
}
/*######################################################################*/

p_Lista realoca(p_Lista lista){

    int endereco, tamanho, novoTamanho;
    p_No auxiliar = lista->inicio->proximo;

    scanf("%d %d %d", &endereco, &tamanho, &novoTamanho);
    /* pára o ponteiro auxiliar na desalocação seguinte ao segmento que será realocado */
    while(auxiliar->endereco < endereco)
        auxiliar = auxiliar->proximo;

    if(tamanho >= novoTamanho){
        /* desaloca a memória que sobrará do novo segmento */
        lista = desaloca(lista, endereco+novoTamanho, tamanho-novoTamanho);
        /* remove os nós com tamanho 0 */
        lista = removeZerados(lista);

        return lista;
    }
    else{
		
        if((novoTamanho <= (tamanho + auxiliar->tamanho)) && (endereco + tamanho == auxiliar->endereco)){

            auxiliar->tamanho  -= (novoTamanho - tamanho);
            auxiliar->endereco += (novoTamanho - tamanho);

            /* remove os nós com tamanho 0 */
            lista = removeZerados(lista);

            return lista;
        }
        else{
            auxiliar = lista->inicio->proximo;
            /* encontra o próximo segmento desalocado que caiba... */
            while(auxiliar->tamanho < novoTamanho)
                auxiliar = auxiliar->proximo;
            /* ...e o aloca nesse nó */
            auxiliar->tamanho  -= novoTamanho;
            auxiliar->endereco += novoTamanho;
            /* remove os nós com tamanho 0 */
            lista = removeZerados(lista);
            /* desaloca o antigo espaço alocado */
            lista = desaloca(lista, endereco, tamanho);
            /* remove os nós com tamanho 0 */
            lista = removeZerados(lista);

            return lista;
        }
    }

    return lista;
}