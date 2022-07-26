#include "pilha.h"
#include <string.h>
/* TAD para uma fila de strings, para futura impressão */
typedef struct String{
    int alegoria;
    int rua;
    int tipo;
    struct String* proximo;
} String;

typedef struct Fila{
    String* inicio;
    String* fim;
} Fila;

typedef String* p_String;
typedef Fila* p_Fila;
/* funções para a fila de strings */
p_Fila criaFila();
void enfileira(p_Fila fila, int alegoria, int rua, int tipo);
void desenfileira(p_Fila fila);
void destroiFila(p_Fila fila);
/* funções que dizem respeito ao desfile */
void chegadaDasAlegorias(p_Pilha antesDoDesfile, int n);
void destroiString(char* string);
void destroiVetorDePilha(pp_Pilha pilha, int r);
void DESFILE(p_Pilha antesDoDesfile, int r);

int main(void){

    int n, r;
    p_Pilha antesDoDesfile;

    criaPilha(&antesDoDesfile);
    /* entra com o número de alegorias e de ruas auxiliares */
    scanf("%d %d", &n, &r);
    /* entra com os dados pra cada alegoria */
    chegadaDasAlegorias(antesDoDesfile, n);
    /* o desfile acontece, se possível, ou não acontece */
    DESFILE(antesDoDesfile, r);

    destroiPilha(antesDoDesfile);

    return 0;
}
/*##########################################################################################################*/
/*###################################################################### FUNÇÕES PARA FILA DE STRINGS ######*/
p_Fila criaFila(){

    p_Fila fila;
    fila = malloc(sizeof(Fila));
    fila->inicio        = NULL;
    fila->fim           = NULL;

    return fila;
}

void enfileira(p_Fila fila, int alegoria, int rua, int tipo){

    p_String novo = malloc(sizeof(String));

    novo->alegoria = alegoria;
    novo->rua      = rua;
    novo->tipo     = tipo;
    novo->proximo  = NULL;

    if(fila->inicio == NULL)
        fila->inicio = novo;
    else
        fila->fim->proximo = novo;

    fila->fim = novo;
}

void desenfileira(p_Fila fila){

    p_String primeiro = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL)
        fila->fim = NULL;

    primeiro->proximo = NULL;

    switch(primeiro->tipo){

        case 0: printf("Desfile pode ser realizado:\n"); break;
        case 1: printf("Alegoria %d desfila.\n", primeiro->alegoria); break;
        case 2: printf("Alegoria %d entra na rua %d e aguarda.\n", primeiro->alegoria, primeiro->rua); break;
        case 3: printf("Alegoria %d sai da rua %d e desfila.\n", primeiro->alegoria, primeiro->rua); break;
    }

    free(primeiro);
}

void destroiFila(p_Fila fila){
/* no final, a fila possui apenas 1 elemento, apontado por fila->inicio */
    free(fila->inicio);
    free(fila);
}

/*##########################################################################################################*/
/*################################################################################ FUNÇÕES DO DESFILE ######*/

void chegadaDasAlegorias(p_Pilha antesDoDesfile, int n){

    int i, x;
    p_Pilha auxiliar;
    criaPilha(&auxiliar);
    /* empilha na ordem contrária numa pilha auxiliar */
    for(i=0; i<n; i++){

        scanf(" %d", &x);
        empilha(auxiliar, x);
    }
    /* desempilha na ordem correta na pilha antesDoDesfile */
    for(i=0; i<n; i++){

        empilha(antesDoDesfile, desempilha(auxiliar));
    }
    free(auxiliar);
}

void destroiString(char* string){

    free(string);
}

void destroiVetorDePilha(pp_Pilha pilha, int r){

    int i;

    for(i=0; i<r; i++){

        destroiPilha(pilha[i]);
    }

    free(pilha);
}

void DESFILE(p_Pilha antesDoDesfile, int r){

    int i;
    int tamanhoAntesDoDesfile = antesDoDesfile->tamanho;
    int proximaAlegoria = 1;
    int empilhouNaAuxiliar = 0;
    int desfilePossivel = 1;
    pp_Pilha auxiliar = malloc(r*sizeof(p_Pilha));
    p_Pilha depoisDoDesfile;
    p_Fila filaString = criaFila();

    criaPilha(&depoisDoDesfile);
    for(i=0; i<r; i++)
        criaPilha(&auxiliar[i]);

    enfileira(filaString, -1, -1, 0);

    /* realiza operações até que o número de alegorias desfiladas seja igual
    ao número de alegorias na pilha de entrada de alegorias */
    while(depoisDoDesfile->tamanho != tamanhoAntesDoDesfile){

        if(buscaTopo(antesDoDesfile) == proximaAlegoria){
            /* se for a próxima a desfilar, a alegoria desfila */
            empilha(depoisDoDesfile, desempilha(antesDoDesfile));
            enfileira(filaString, proximaAlegoria, -1, 1);
            
            proximaAlegoria++;
        }
        else{ /* senão é empilhada, se possível, nas ruas auxiliares*/

            for(i=0; i<r; i++){
                /* caso onde a rua auxiliar já possua alegorias ou caso onde a rua auxiliar esteja vazia*/
                if((auxiliar[i]->topo != NULL && buscaTopo(antesDoDesfile) < buscaTopo(auxiliar[i])) || auxiliar[i]->topo == NULL){

                    empilha(auxiliar[i], desempilha(antesDoDesfile));
                    enfileira(filaString, buscaTopo(auxiliar[i]), i+1, 2);
                    
                    empilhouNaAuxiliar = 1;
                    break;
                }
            }
            if(!empilhouNaAuxiliar){ /* se a alegoria não for empilhada, o jogo não é possível */

                desfilePossivel = 0;
                printf("Sem desfile.\n");
                break;
            }

            empilhouNaAuxiliar =0;
        }
        /* depois de empilhar a alegoria, confere se é possível desfilar alguma alegoria */
        if(desfilePossivel){

            for(i=0; i<r; i++){

                if(buscaTopo(auxiliar[i]) == proximaAlegoria){

                    while(buscaTopo(auxiliar[i]) == proximaAlegoria){

                        empilha(depoisDoDesfile, desempilha(auxiliar[i]));
                        enfileira(filaString, buscaTopo(depoisDoDesfile), i+1, 3);
                        
                        proximaAlegoria++;
                    }

                    i=-1;
                }
            }
        }
    }

    if(desfilePossivel)
        while(filaString->inicio != NULL)
            desenfileira(filaString);

    destroiFila(filaString);
    destroiPilha(depoisDoDesfile);
    destroiVetorDePilha(auxiliar, r);
}
 /* valgrind --leak-check=full ./main < tests/arq17.in */