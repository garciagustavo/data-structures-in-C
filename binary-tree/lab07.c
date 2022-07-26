#include "arv_binaria.h"
#include "pilha.h"

int potencia(int num, int exp);
void destacarNos(p_No no1, p_No no2, int distancia1, int distancia2);

int main(void){

    int i, h1, h2, quantidadeH1, quantidadeH2;
    char nome[20];
    p_No arvore1=NULL, arvore2=NULL;
    p_Pilha pilha;
    /* são entradas as alturas de duas árvores */
    scanf("%d %d", &h1, &h2);
    /* são calculadas as quantidades de nós de ambas as árvores */
    quantidadeH1 = potencia(2,h1) -1;
    quantidadeH2 = potencia(2,h2) -1;
    /* criada a pilha pra auxiliar entrada dos nomes e construção das árvores */
    pilha = criaPilha();
    /* empilha os nomes de entrada p/ desempilhar na construção da árvore1 */
    for(i=0; i < quantidadeH1; i++){

        scanf(" %s", nome);
        empilha(pilha, nome);
    }
    arvore1 = construirArvore(arvore1, pilha, h1);
    /* empilha os nomes de entrada p/ desempilhar na construção da árvore2 */
    for(i=0; i<quantidadeH2; i++){

        scanf(" %s", nome);
        empilha(pilha, nome);
    }
    arvore2 = construirArvore(arvore2, pilha, h2);
    /* destaca os nós das árvores que serão impressos */
    destacarNos(arvore1, arvore2, 0, 0);
    /* imprime apenas os nós destacados das árvores em pré-ordem */
    imprimeArvorePre(arvore1, h1);
    printf("\n");
    imprimeArvorePre(arvore2, h2);
    printf("\n");
    /* desaloca as árvores e a pilha */
    arvore1 = destroiArvore(arvore1);
    arvore2 = destroiArvore(arvore2);
    destroiPilha(pilha);

    return 0;
}
/*##########################################################*/

int potencia(int num, int exp){

    int i, aux=num;

    for(i=0; i<(exp-1); i++)
        num = num*aux;

    return num;
}

void destacarNos(p_No no1, p_No no2, int distancia1, int distancia2){

    if(no1 != NULL){
        /* se a árvore2 tem o nó, esse é destacado lá, e depois aqui */
        if(temNoNaArvore(no2, no1->nome, distancia2)){

            no1->distancia = distancia1;
        }

        destacarNos(no1->esq, no2, distancia1 +1, distancia2);
        destacarNos(no1->dir, no2, distancia1 +1, distancia2);		
    }
}