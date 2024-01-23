#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union genero
{
	char feminino[10];
	char masculino[10];
	
	
}Genero;


typedef struct pessoa
{
	char nome[30];
	int idade;	
	Genero genero;
}Pessoa;

void dadosPessoa(Pessoa * pessoa)
{
	int op;
    //funçao que preenche os dados de uma variavel do tipo pessoa(struct)
    printf("informe o nome\n");
    scanf(" %[^\n]", pessoa->nome); //usa setinha pois eh ponteiro
    printf("\n informe a idade");
    scanf("%d", &pessoa->idade);
    printf("Digite 0 para feminino e 1 para masculino");
    scanf("%d", &op);
    
    if(op){
        strcpy(pessoa->genero.masculino, "MASCULINO");
    	
	}
	else{
        strcpy(pessoa->genero.feminino, "FEMININO");
		}

	 
}


int main(void)
{
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    dadosPessoa(pessoa);
    printf("nome: %s\n", pessoa->nome);
    printf("idade %d \n", pessoa->idade);
    printf("genero: %s \n", pessoa->genero.masculino);
    free(pessoa);
    return 0;
}