#include "aluno.h"

void ler_aluno(Aluno *aluno){

	int i;

	scanf("%s", aluno->nome);
	scanf("%s", aluno->sobrenome);
	scanf("%lf", &aluno->media);
	scanf("%d", &aluno->num_disciplinas);
	/* escaneia todas as disciplinas que o aluno cursa */
	for(i=0; i<aluno->num_disciplinas; i++)
		scanf("%s", aluno->disciplinas[i]);
}