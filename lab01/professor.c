#include "professor.h"

void ler_professor(Professor *professor){

	scanf("%s", professor->nome);
	scanf("%s", professor->sobrenome);
	scanf("%lf", &professor->salario);
	scanf("%s", professor->disciplina);
}

void aumento(Professor *professor, double porcentagem){

	professor->salario = professor->salario + (professor->salario * porcentagem);
}