#include "hash.h"

int main(void){

    int flag=0;
    char chave[50];
    p_hash tabela = criar_hash();

    scanf("%[^\n]s", chave);
    /* sai do loop apenas com o break no if ao final do escopo */
    while(1){

        flag = buscar(tabela, chave);
        /* se não encontrou a chave, a insere na tabela... */
        if(flag == 0){

            inserir(tabela, chave);
            printf("%d %s\n", flag, chave);
        }
        else /* senão apenas imprime a chave sinalizando que já foi vista */
            printf("%d %s\n", flag, chave);

        scanf(" %[^\n]s", chave);

        /* caso que interrompe o loop e sai do programa */
        if(chave[0] == '#' && chave[1] == '\0')
            break;
    }

    destruir_hash(tabela);

    return 0;
}