#include <malloc.h>
#include "lab01.h"

/* função que compara duas strings, no caso, duas disciplinas */
int disciplinasCorrespondentes(char *string1, char *string2){
	int i, comparador=0;
	/* comparando letra a letra */
	for(i=0; i<5; i++){
		if(string1[i] == string2[i])
			comparador = 1;
		else
			return 0;
	}
	/* e retornando 1, caso sejam disciplinas corrrespondentes */
	return comparador;
}
/* função que calcula a porcentagem que será aumentada do salário */
int calculaPorcentagem(double *medias, int n){
	int i, porcentagem=0;
	double menor=11;
	/* encontra a menor media dos alunos do professor */
	for(i=0; i<n; i++){
		if(medias[i] < menor && medias[i] != 0)
			menor = medias[i];
	}
	/* confere a menor média, e retorna a porcentagem devida de aumento, ou 0 */
	if(menor == 10)
		porcentagem = 15;
	if(menor >= 9 && menor < 10)
		porcentagem = 10;
	if(menor >= 8.5 && menor < 9)
		porcentagem = 5;
	if(menor < 8.5)
		porcentagem = 0;

	return porcentagem;
}

void ler_professores(Professor *professores, int n){
	int i;
	/* Uma repetição para ler n professores no vetor */
	for(i=0; i<n; i++)
		ler_professor(&professores[i]);
}

void ler_alunos(Aluno *alunos, int n){
	int i;
	/* Uma repetição para ler n alunos no vetor */
	for(i=0; i<n; i++)
		ler_aluno(&alunos[i]);
}

void aplicar_aumento(Professor *professores, int np, Aluno *alunos, int na){
	/* por convenção,  */
	int i, j, k, porcentagem=0;
	double *medias;
	/* aloca memória pra um vetor onde vão ser colocadas as médias de todos os alunos, de cada professor */
	medias = malloc(na*sizeof(double));
	/* preenche o vetor medias com 0 em todas as posições */
	for(i=0; i<na; i++)
		medias[i] = 0;
	/* confere as médias de todos os alunos do professor i */
	for(i=0; i<np; i++){
		/* confere se cada aluno j cursa a disciplina do professor i */
		for(j=0; j<na; j++){
			/* procura pela disciplina do professor i em cada uma das k disciplinas do aluno j */
			for(k=0; k<alunos[j].num_disciplinas; k++){
				/* se o aluno j cursa a disciplina do professor i, sua média é guardada no vetor medias */
				if(disciplinasCorrespondentes(professores[i].disciplina, alunos[j].disciplinas[k])){

					medias[j] = alunos[j].media;
					break;
				}
				/* senão a posição do vetor medias continua 0 */
				else
					medias[j] = 0;
			}
		}/* no final, o vetor medias estará ocupado com as medias de todos alunos que cursam a disciplina do
		professor i, ou zeros */

		/* o vetor medias é consumido pra designar o aumento do professor i */
		porcentagem = calculaPorcentagem(medias, na);
		/* é realizado o aumento de salário do professor i, ou não, caso o aumento seja 0 */
		if(porcentagem == 0)
			aumento(&professores[i], 0);
		if(porcentagem == 15)
			aumento(&professores[i], 0.15);
		if(porcentagem == 10)
			aumento(&professores[i], 0.1);
		if(porcentagem == 5)
			aumento(&professores[i], 0.05);
	}
	/* desalocando o vetor media */
	free(medias);
}

void imprimir_professores(Professor *professores, int np){

	int i;
	/* Uma repetição para imprimir os np professores do vetor */
	for(i=0; i<np; i++)
		printf("%s %s %.2f\n", professores[i].nome,
								professores[i].sobrenome,
								professores[i].salario
								);
}