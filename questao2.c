#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


typedef union tipo{
    char alimento[15];
    char bebida[15];
    char eletronico[15];
}Tipo;

typedef struct produto{
    char nome[20];
    int valor;
    Tipo tipo;

}Produto;


void cadastrarProduto(Produto * produto)
{
    int op;
    printf("informe o nome: \n");
    scanf(" %[^\n]", produto->nome);
    printf("informe o valor: \n");
    scanf("%d", &produto->valor);
    printf("informe o tipo do produto:\n 0.alimento \n 1. bebida \n 2. eletronico \n");
    scanf("%d", &op);

    switch (op)
    {
    case 0: 
      strcpy(produto->tipo.alimento, "ALIMENTO");
        break;
    case 1:
      strcpy(produto->tipo.bebida, "BEBIDA");
        break;
    case 2:
      strcpy(produto->tipo.eletronico, "ELETRONICO");
        break;
    }
};



int main(void){
    Produto * produto = malloc(sizeof(Produto));
    cadastrarProduto(produto);
    printf("nome: %s\n", produto->nome);
    printf("idade %d \n", produto->valor);
    printf("tipo: %s \n", produto->tipo.alimento);
    free(produto);
}