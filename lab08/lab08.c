#include "abb.h"

int main(void){
    /* declaração do operador, da string que o segue e da árvore de livros */
    char op, string[80];
    p_no livros=NULL;

    scanf("%c", &op);
    /* enquanto op não for # (fim) o programa roda */
    while(op != '#'){
        /* entra com o nome do livro ou o trecho do nome a ser procurado */
        scanf("%[^\n]s", string);
        /* adiciona, remove ou lista de acordo com os dígitos +, - ou $, respectivamente */
        switch(op){

            case '+': livros = adicionar(livros, string); break;
            case '-': livros = remover(livros, string); break;
            case '$': printf("Sugestoes para prefixo \"%s\":\n", string); 
                      imprimirEmOrdem(livros, string); break;
        }
        /* entra com o operador da próxima ação */
        scanf(" %c", &op);
        /* caso o operador seja de saída, lê sua string "fim" */
        if(op == '#'){
            scanf("%s", string);
        }
    }
    /* desaloca memória da árvore que sobrou depois das operações */
    destruirABB(livros);

    return 0;
}