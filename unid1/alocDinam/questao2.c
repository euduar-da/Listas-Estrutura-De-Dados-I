#include <stdio.h>
#include <stdlib.h>

int main(){
    int continuar_Respondendo;
    int questoes = 1;
    int * questoesP = &questoes;
    //o gabarito da prova tem que ser do tamanho do total de questões
    int * gabaritoProva = (int *) malloc ((*questoesP) * sizeof (int));
}

void menu(){
    printf("insira o total de questões que a prova possui \n");
    scanf("%d", &);
}