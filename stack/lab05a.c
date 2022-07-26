#include "pilha.h"
#include <string.h>

void chegadaDasAlegorias(p_Pilha antesDoDesfile, int n);
void destroiString(char* string);
void DESFILE(p_Pilha antesDoDesfile, int r);

int main(void){

    int n, r;
    p_Pilha antesDoDesfile;

    antesDoDesfile  = criaPilha();

    scanf("%d %d", &n, &r);

    chegadaDasAlegorias(antesDoDesfile, n);

    DESFILE(antesDoDesfile, r);

    destroiPilha(antesDoDesfile);

    return 0;
}
/*################################################# FUNÇÕES DO DESFILE ######*/

void chegadaDasAlegorias(p_Pilha antesDoDesfile, int n){

    int i, x;
    p_Pilha auxiliar = criaPilha();
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

void DESFILE(p_Pilha antesDoDesfile, int r){

    int i;
    int tamanhoAntesDoDesfile = antesDoDesfile->tamanho;
    int proximaAlegoria = 1;
    int empilhouNaAuxiliar = 0;
    int desfilePossivel = 1;
    char* stringFixa = malloc(40*sizeof(char));
    char* stringTemp = malloc(40*sizeof(char));
    p_Pilha depoisDoDesfile = criaPilha();
    pp_Pilha auxiliar = malloc(r*sizeof(p_Pilha));
    for(i=0; i<r; i++)
        auxiliar[i] = criaPilha();

    sprintf(stringFixa, "Desfile pode ser realizado:\n");

    /* realiza operações até que o número de alegorias desfiladas seja igual
    ao número de alegorias na pilha de entrada de alegorias */
    while(depoisDoDesfile->tamanho != tamanhoAntesDoDesfile){

        if(buscaTopo(antesDoDesfile) == proximaAlegoria){
            /* se for a próxima a desfilar, a alegoria desfila */
            empilha(depoisDoDesfile, desempilha(antesDoDesfile));
            sprintf(stringTemp, "Alegoria %d desfila.\n", proximaAlegoria);
            stringFixa = realloc(stringFixa, (strlen(stringFixa)+40)*sizeof(char));
            strcat(stringFixa, stringTemp);
            proximaAlegoria++;
        }
        else{ /* senão é empilhada, se possível, nas ruas auxiliares*/

            for(i=0; i<r; i++){
                /* caso onde a rua auxiliar já possui alegorias */
                if(auxiliar[i]->topo != NULL && buscaTopo(antesDoDesfile) < buscaTopo(auxiliar[i])){

                    empilha(auxiliar[i], desempilha(antesDoDesfile));
                    sprintf(stringTemp, "Alegoria %d entra na rua %d e aguarda.\n", buscaTopo(auxiliar[i]), i+1);
                    stringFixa = realloc(stringFixa, (strlen(stringFixa)+40)*sizeof(char));
                    strcat(stringFixa, stringTemp);
                    empilhouNaAuxiliar = 1;
                    break;
                }/* e caso onde a rua auxiliar está vazia */
                else if(auxiliar[i]->topo == NULL){

                    empilha(auxiliar[i], desempilha(antesDoDesfile));
                    sprintf(stringTemp, "Alegoria %d entra na rua %d e aguarda.\n", buscaTopo(auxiliar[i]), i+1);
                    stringFixa = realloc(stringFixa, (strlen(stringFixa)+40)*sizeof(char));
                    strcat(stringFixa, stringTemp);
                    empilhouNaAuxiliar = 1;
                    break;
                }
            }
            if(!empilhouNaAuxiliar){ /* se a alegoria não for empilhada, o jogo não ś possível */

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
                        sprintf(stringTemp, "Alegoria %d sai da rua %d e desfila.\n", buscaTopo(depoisDoDesfile), i+1);
                        stringFixa = realloc(stringFixa, (strlen(stringFixa)+40)*sizeof(char));
                        strcat(stringFixa, stringTemp);
                        proximaAlegoria++;
                    }

                    i=-1;
                }
            }
        }
    }

    if(desfilePossivel)
        printf("%s", stringFixa);

    destroiString(stringFixa);
    destroiString(stringTemp);
    destroiVetorDePilha(auxiliar, r);
    destroiPilha(depoisDoDesfile);
}