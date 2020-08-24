#include "grafo.h"

p_grafo criar_grafo(int m, int n){

    int i, j;
    p_grafo g = malloc(sizeof(Grafo));

    g->m = m;
    g->n = n;
    /* aloca uma matriz de adjacência (m*n)x(m*n) */
    g->adj = malloc(m*n * sizeof(int*));
    for(i=0; i<m*n; i++)
        g->adj[i] = malloc(m*n * sizeof(int));
    /* inicializa todas as células com 0 */
    for(i=0; i<m*n; i++)
        for(j=0; j<m*n; j++)
            g->adj[i][j] = 0;

    return g;
}

int tem_aresta(){

    return 0;
}

void define_matriz_adj(p_grafo g, int** mapa, int m, int n, int h){
/* essa função olha cada posição do mapa de relevo e define
   com quais dos 4 vizinhos essa posição se conecta */

    int i, j;

    for(i=1; i<(m+1); i++)
        for(j=1; j<(n+1); j++){

            if(mapa[i][j] <= h){
            /* caso o vizinho seja menor que a altura e não seja borda, cria conexão */
                if(mapa[i-1][j] != -1 && mapa[i-1][j] <= h)
                    g->adj[i][j] = inserir_lista(g->adj[i][j], i-1, j);

                if(mapa[i-1][j] != -1 && mapa[i][j-1] <= h)
                    g->adj[i][j] = inserir_lista(g->adj[i][j], i, j-1);

                if(mapa[i-1][j] != -1 && mapa[i+1][j] <= h)
                    g->adj[i][j] = inserir_lista(g->adj[i][j], i+1, j);

                if(mapa[i-1][j] != -1 && mapa[i][j+1] <= h)
                    g->adj[i][j] = inserir_lista(g->adj[i][j], i, j+1);
            }
        }
}

void destroi_grafo(p_grafo g){

    int i, j;
    
    for(i=0; i<g->m; i++)
        for(j=0; j<g->n; j++){
            /* desaloca cada lista ligada, se existir */
            if(g->adj[i][j] != NULL)
                destroi_lista(g->adj[i][j]);
        }
    /* desaloca os vetores de ponteiros */
    for(i=0; i<g->m; i++)
        free(g->adj[i]);
    /* desaloca a matriz de adjacências */
    free(g->adj);
    free(g); /* e finalmente dealoca o grafo */
}