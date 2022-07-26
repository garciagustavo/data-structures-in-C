/*
VÉRTICES = cada ponto do relevo
ARESTAS  = cada ligação possível entre pontos do relevo

Se um ponto do relevo é menor ou igual a altura que o drone alcança,
esse ponto pode se conectar com seus vizinhos, desde que o vizinho
tenha relevo menor ou igual a altura.
*/

#include "grafo.h"

int**  criar_mapa(int m, int n);
char** inicializa_resultado(int m, int n);
void   destroi_mapa(int** mapa, int m);

int main(void){

    int h, x, y, a, b, m, n, i, j, relevo, **mapa;
    char **matriz_resultado;
    p_grafo grafo;

    scanf("%d %d %d", &h, &x, &y);
    scanf(" %d %d %d %d", &a, &b, &m, &n);

    mapa  = criar_mapa(m, n);
    grafo = criar_grafo(m, n);

    /* preenche a matriz que representa o mapa de relevo... */
    for(i=0; i<m; i++)
        for(j=0; j<n; j++){
            /* ...conservando a borda da matriz com valores -1 */
            scanf(" %d", &relevo);
            mapa[i][j] = relevo;
        }

    define_matriz_adj(grafo, mapa, m, n, h);

    matriz_resultado = inicializa_resultado(m, n);

    /* desaloca memória da matriz mapa e do grafo */
    destroi_mapa(mapa, m);
    destroi_grafo(grafo);

    return 0;
}



/*######################################### Funções auxiliares*/
int** criar_mapa(int m, int n){

    int i, j, **mapa = malloc(m * sizeof(int*));

    for(i=0; i<m; i++)
        mapa[i] = malloc(n * sizeof(int));
    
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            mapa[i][j] = -1;

    return mapa;
}

char** inicializa_resultado(int m, int n){
/* essa função devolve uma matriz MxN com '# em todas as posições' */

    int i, j;

    char** resultado = malloc(m * sizeof(char*));

    for(i=0; i<m; i++)
        resultado[i] =malloc(n * sizeof(char));

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            resultado[i][j] = '#';

    return resultado;
}

void destroi_mapa(int** mapa, int m){

    int i;
    
    for(i=0; i<(m+2); i++)
        free(mapa[i]);

    free(mapa);
}