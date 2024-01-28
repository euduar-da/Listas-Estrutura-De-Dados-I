#include <stdio.h>
#include <stdlib.h>


typedef enum tipos{
    alimento,
    bebida,
    eletronico
}Tipos;

typedef struct produto{
    char nome[20];
    int preco;
    Tipos tipos;
}Produto;


void getDados(Produto * produto){
    printf("Informe o nome: \n");
    scanf("%[^\n]", produto->nome);
    printf("informe o preco: \n");
    scanf("%d", &produto->preco);
    printf("informe o tipo de produto: \n 0- alimento \n 1- bebida \n 2- eletronico \n");
    scanf("%d", &produto -> tipos);
}

void imprimeProduto(Produto * produto){
    printf("nome: %s \n Idade: %d \n", produto ->nome, produto->preco);
    if(produto->tipos == alimento){
        printf("o tipo do produto eh alimento");
    }else if(produto->tipos == bebida){
                printf("o tipo do produto eh bebida");
    }else if(produto->tipos == eletronico){
                printf("o tipo do produto eh eletronico");
    }

}

int main(void){
    Produto * produto = malloc(sizeof(Produto));
    getDados(produto);
    imprimeProduto(produto);
    free(produto);

    return 0;
}