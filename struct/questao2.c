#include <stdio.h>
#include <stdlib.h>


typedef struct dadosPessoa
{
    char nome[80];
    int numDoc;
    int idade;

};

void cadastroFuncionario(struct dadosPessoa *dados, int qtdPessoa);
void imprimirDados(struct dadosPessoa * dados, int qtdPessoa);
void atualizarIdade(struct dadosPessoa * dados, int qtdPessoa);
void comparacaoIdade(struct dadosPessoa * dados, int qtdPessoa);
int main(void){
    int i;
    int qtdPessoa = 3;
    struct dadosPessoa * dados = malloc(qtdPessoa *sizeof(struct dadosPessoa));
     if (dados == NULL){
        exit(1);
    }

    cadastrar(dados, qtdPessoa);
    imprimirDados(dados, qtdPessoa);
    atualizarIdade(dados,qtdPessoa);
    
}

void cadastrar(struct dadosPessoa * dados, int qtdPessoa)
{
    int i;
    for (i = 0; i < qtdPessoa; i++){
    printf("cadastre o nome da pessoa: \n");
    scanf("%[^\n]", dados->nome);
    printf("cadastre o num do documento: \n");
    scanf("%d", &dados->numDoc);
    printf("cadastre a idade da pessoa: \n");
    scanf("%d", &dados->idade);
    }

};

void imprimirDados(struct dadosPessoa * dados, int qtdPessoa)
{
    int i;
    for(i=0; i < qtdPessoa; i++){
    printf("nome: \n", dados->nome);
    printf("num documento: \n", dados->numDoc);
    printf("idade: \n", dados->idade);
    }
};

void atualizarIdade(struct dadosPessoa * dados, int qtdPessoa)
{
    int i;
    for(i = 0; i < qtdPessoa; i++){
   printf("%s \n", dados[i].nome);
   printf("digite a nova idade: \n");
   scanf("%d", &dados[i].idade);
   
    }
}

void comparacaoIdade(struct dadosPessoa * dados, int qtdPessoa ){

}
