#include "fila_prioridade.h"

void inicializar_processo(Processo processo);
void inicializar_fila(p_fp fprio, int tamanho);
Processo criar_processo(int id, int clock, int prioridade, int dependencia);
void destroi_processados(int* processados);
void destroi_nucleo(p_processo nucleo);

int main(void){

    int i, n, p, id, clock, prioridade, dependencia, relogio=0;
    int* processados;
    p_fp filaPrio;
    p_processo nucleo;
    p_processo auxiliar;
    /* as quantidades de núcleos e processos são entrados */
    scanf("%d %d", &n, &p);
    /* a fila de prioridade é criada e inicializada */
    filaPrio = criar_filaprio(p);
    inicializar_fila(filaPrio, p);
    /* é criado um processador com n núcleos, inicializando-os */
    nucleo = malloc(n*sizeof(Processo));
    for(i=0; i<n; i++)
        inicializar_processo(nucleo[i]);
    /* um vetor de processos pra auxiliar a entrada dos dados é criado e inicializado */
    auxiliar = malloc(p*sizeof(Processo));
    for(i=0; i<p; i++)
        inicializar_processo(auxiliar[i]);
    /* os dados de cada processo são entrados num vetor auxiliar */
    for(i=0; i<p; i++){
        /* ...criando-se um processo pra cada inserção */
        scanf(" %d %d %d %d", &id, &clock, &prioridade, &dependencia);
        auxiliar[i] = criar_processo(id, clock, prioridade, dependencia);
    }
    /* cada processo com dependência passa a ter "prioridade da dependência -1" */
    auxiliar = acertaPrioridades(auxiliar, p);
    /* finalmente os processos sobem pra heap */
    for(i=0; i<p; i++){

        insere(filaPrio , auxiliar[i]);
    }
    
    /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*
- os processos com maior prioridade são executados pelos n núcleos
- em caso de empate, o menor identificador
- seleciona o processo com maior prioridade quando um núcleo está livre
- em caso de mais de um núcleo livre, o de menor identificador
- quando se passarem os clocks, o processo é encerrado
- um proceso só executa depois  da dependencia
  printf("processo %d iniciou no clock %d", );
  printf("processo %d encerrou no clock %d", );
*/  /* enquanto a fila possui algum processo, o core roda */
    while(filaPrio->n != 0){
        /* ...e se mantém procurando um núcleo vazio */
        for(i=0; i<n; i++){

            if(nucleo[i].id == -1){

                nucleo[i] = extrai_maximo(filaPrio->processo)
            }
        }

        relogio++;
    }

    /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    destroi_fila(filaPrio);
    destroi_processados(processados);
    destroi_nucleo(nucleo);

    return 0;
}
/*########################################################################*/

void inicializar_processo(Processo processo){

    processo.id          = -1;
    processo.clock       = -1;
    processo.prioridade  = -1;
    processo.dependencia = -1;
}

void inicializar_fila(p_fp fprio, int tamanho){

    int i;
    /* inicializa o vetor de processos */
    for(i=0; i<tamanho; i++){

        inicializar_processo(fprio->processo[i]);
    }
    /* inicializa o vetor com as id's dos processados */
    for(i=0; i<tamanho; i++)
        fprio->processados[i] = -1;
}

Processo criar_processo(int id, int clock, int prioridade, int dependencia){

    Processo novo;

    novo.id          = id;
    novo.clock       = clock;
    novo.prioridade  = prioridade;
    novo.dependencia = dependencia;

    return novo;
}

p_processo acertaPrioridades(p_processo auxiliar, int quantidade){

    int i;
    /*
    uma vez que os processos já chegam ordenados por id para o teste:
    - toda dependência está na posição dependência-1
    - todo processo passa a ter dependência = prioridade da sua dependência menos 1
    - os processos sem dependência continuam com dependência = 0
    */
    for(i=0; i<quantidade; i++){

        if(auxiliar[i].prioridade != 0)
            auxiliar[i].prioridade = auxiliar[auxiliar[i].dependencia-1].prioridade - 1;
    }

    

    return auxiliar;
}

void destroi_processados(int* processados){

    free(processados);
}

void destroi_nucleo(p_processo nucleo){

    free(nucleo);
}

/*
int procuraProcessoPermitido(p_fp fprio, int quantidade){

    int i;

    if(fprio->processo[0].dependencia == 0)
        return 0;
    for(i=0; i<quantidade; i++)
        for(j=0; j<quantidade; j++)
            if(fprio->processo[i].dependencia == fprio->processados[j])
                return i;
}
*/