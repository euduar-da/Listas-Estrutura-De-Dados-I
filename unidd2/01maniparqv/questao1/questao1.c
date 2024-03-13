#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[20];
    float nota1;
    float nota2;
    float nota3;
    float media;
    char situacao[10];
}Aluno;

void getQtdAlunos();
void getDados();
void calculaMedia();
void checarSituacao();
void escreveDados();

int main(void){
    //abrindo arquivo
    FILE* entrada = fopen("entrada_q3.txt", "r");
    int qtdAlunos = 0;

    //analisando a quantidade de alunos no arquivo
    getQtdAlunos(entrada, &qtdAlunos);

    rewind(entrada);// unica solução que encontrei 

    //criando array de ponteiro para armazenar os dados
    Aluno * aluno = (Aluno* ) malloc(qtdAlunos * sizeof(Aluno));

    //funcão para ler os dados e armazenar na variavel
    getDados(entrada, qtdAlunos, aluno);

    fclose(entrada);

    //funcao para calcular media
    calculaMedia(qtdAlunos, aluno);

    //funcao para checar situação do aluno
    checarSituacao(aluno, qtdAlunos);

    //cria novo arquivo .txt
    FILE * saida = fopen("saida_q3.txt", "w");

    // escreve dados no saida_q3.txt
    escreveDados(saida, qtdAlunos, aluno);
    
    //fechar arquivo
    fclose(saida);

    //libera memoria
    free(aluno);
    
    return 0;
}

void getQtdAlunos(FILE * entrada, int * qtdAlunos){
    int c;
    while( (c = fgetc(entrada)) != EOF){ //enquanto receber caractere diferente de EOF (end of file oou final do arquivo)
        if(c == '\n'){
            (*qtdAlunos)++;
        }
    }

    (*qtdAlunos)++; 
}

void getDados(FILE * entrada, int qtdAlunos, Aluno * aluno){
    int i;

    for(i = 0; i < qtdAlunos; i++){
        fscanf(entrada, "%s%f%f%f", aluno[i].nome, &aluno[i].nota1, &aluno[i].nota2, &aluno[i].nota3);
    }
}

void calculaMedia(int qtdAlunos, Aluno * aluno){
    int i = 0;
    for(i=0; i < qtdAlunos; i++){
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3 ;
    }
}

void checarSituacao(Aluno * aluno, int qtdAlunos){
    int i = 0;
    for(i = 0; i < qtdAlunos; i++){
        if (aluno[i].media >= 7){
            strcpy(aluno[i].situacao, "Aprovado");       
        }else{
            strcpy(aluno[i].situacao, "Reprovado");
        }
    }
} 

void escreveDados(FILE * saida, int qtdAlunos, Aluno * aluno){
    int i;
    for(i = 0; i < qtdAlunos; i++){
        fprintf(saida, "%s\t%.2f\t%s\n", aluno[i].nome, aluno[i].media, aluno[i].situacao);
    }
}
