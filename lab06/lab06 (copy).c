#include "fila_prioridade.h"
/*

- os processos com maior prioridade são executados pelos n núcleos
- em caso de empate, o menor identificador
- seleciona o processo com maior prioridade quando um núcleo está livre
- em caso de mais de um núcleo livre, o de menor identificador
- quando se passarem os clocks, o processo é encerrado
- um proceso só executa depois  da dependencia
  printf("processo %d iniciou no clock %d", );
  printf("processo %d encerrou no clock %d", );

*/
int main(void){

    int i, n, p, id, clock, prioridade, dependencia, relogio;
    int* processados;
    p_fp filaPrio;
    p_processo nucleo;
    /* as quantidades de núcleos e processos são entrados */
    scanf("%d %d", &n, &p);
    /* a fila de prioridade é criada */
    filaPrio = criar_filaprio(p);
    /* os dados de cada processo são entrados... */
    processados = malloc(n*sizeof(int));
    for(i=0; i<p; i++){
        /* ...criando-se um processo pra cada inserção */
        scanf(" %d %d %d %d", &id, &clock, &prioridade, &dependencia);
        insere(filaPrio , criar_processo(id, clock, prioridade, dependencia));
    }
    /* é criado um processador com n núcleos, inicializando-os */
    nucleo = malloc(n*sizeof(Processo));
    for(i=0; i<n; i++)
        inicializar_processo(nucleo[i]);
    /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    while(filaPrio->n != 0){
/*

- conferir se algum processo terminou
- conferir se 

*/
        
    }

    /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    destroir_fila(filaPrio);
    destroi_processados(processados);
    destroi_nucleo(nucleo);
    /*
        - destruir processados
        - destruir nucleo
    */

    return 0;
}
/*########################################################################*/

void inicializar_processo(p_processo processo){

    processo.id          = -1;
    processo.clock       = -1;
    processo.prioridade  = -1;
    processo.dependencia = -1;
}

void inicializar_fila(p_fp fprio, int tamanho){

    int i;

    for(i=0; i<tamanho; i++){

        inicializar_processo(&(fprio->processo[i]));
    }
}

Processo criar_processo(int id, int clock, int prioridade, int dependencia){

    Processo novo;

    novo->id          = id;
    novo->clock       = clock;
    novo->prioridade  = prioridade;
    novo->dependencia = dependencia;

    return novo;
}

void troca(p_processo processoA, p_processo processoB){

    Processo auxiliar;

    auxiliar   = *processoA;
    *processoA = *processoB;
    *processoB = auxiliar;
}

void destroi_processados(int* processados){

    free(processados);
}

void destroi_nucleo(p_processo nucleo){

    free(nucleo);
}