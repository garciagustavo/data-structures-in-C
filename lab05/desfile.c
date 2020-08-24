void DESFILE(p_Pilha antesDoDesfile, int r){

    int i;
    int tamanhoAntesDoDesfile = antesDoDesfile->tamanho;
    int proximaAlegoria = 1;
    int empilhouNaAuxiliar = 0;
    int desfilePossivel = 1;
    p_Pilha depoisDoDesfile = criaPilha();
    pp_Pilha auxiliar = malloc(r*sizeof(p_Pilha));
    for(i=0; i<r; i++)
        auxiliar[i] = criaPilha();
    /* desempilha a pilha inicial (antesDoDesfile) na pilha depoisDoDesfile ou nas auxiliares */
    while(antesDoDesfile->topo != NULL){
printf("[[1]]\n");
        if(buscaTopo(antesDoDesfile) == proximaAlegoria){
printf("[[2]]\n");
            empilha(depoisDoDesfile, desempilha(antesDoDesfile));
            printf("Alegoria %d desfila.\n", proximaAlegoria);
            proximaAlegoria++;
        }
        else{
printf("[[3]]\n");
            for(i=0; i<r; i++){

                if(auxiliar[i]->topo != NULL && buscaTopo(antesDoDesfile) < buscaTopo(auxiliar[i])){
printf("[[4]]\n");
                    empilha(auxiliar[i], desempilha(antesDoDesfile));
                    printf("Alegoria %d entra na rua %d e aguarda.\n", buscaTopo(auxiliar[i]), i+1);
                    empilhouNaAuxiliar = 1;
                    break;
                }
                else if(auxiliar[i]->topo == NULL){
printf("[[5]]\n");
                    empilha(auxiliar[i], desempilha(antesDoDesfile));
                    printf("Alegoria %d entra na rua %d e aguarda.\n", buscaTopo(auxiliar[i]), i+1);
                    empilhouNaAuxiliar = 1;
                    break;
                }
            }
            if(!empilhouNaAuxiliar){
printf("[[7]]\n");
                desfilePossivel = 0;
                printf("Sem desfile.\n");
                break;
            }
        }

        empilhouNaAuxiliar =0;
    }
    /* desempilha as pilhas auxiliares na depoisDoDesfile, se o desfile for possível */
    if(desfilePossivel){
printf("[[8]]\n");

for(i=0; i<r; i++)
    imprime(auxiliar[i]);

        while(depoisDoDesfile->tamanho != tamanhoAntesDoDesfile){

            for(i=0; i<r; i++){

                if(buscaTopo(auxiliar[i]) == proximaAlegoria){
printf("[[9]]\n");
                    empilha(depoisDoDesfile, desempilha(auxiliar[i]));
                    printf("Alegoria %d sai da rua %d e desfila.\n", buscaTopo(depoisDoDesfile), i+1);
                    proximaAlegoria++;
                }
            }
        }
    }
printf("[[10]]\n");
    destroiPilha(depoisDoDesfile);
}