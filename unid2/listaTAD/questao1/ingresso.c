#include "ingresso.h"
#include <stdio.h>
#include <stdlib.h>

struct ingresso
{
     float preco;
    char local[20];
    char atracao[20];
};



void preenche(Ingresso* ingresso,  int qtdIngresso)
{
    int i;
    for(i = 0; i < qtdIngresso; i++) {
        printf("insira o valor do ingresso: \n");
        scanf("%f", &ingresso[i].preco);
        printf("insira o local: \n");
        scanf(" %[^\n]", ingresso[i].local);
        printf("insira qual a atracao: \n");
        scanf(" %[^\n]", ingresso[i].atracao);
    }
}

void imprime (Ingresso* ingresso, int qtdIngresso)
{
       for(int i = 0; i < qtdIngresso; i++) {
    printf("=================================\n");
    printf("valor: %.2f \n", ingresso[i].preco);
    printf("local: %s \n", ingresso[i].local);
    printf("atracao: %s \n", ingresso[i].atracao);
       }


}

void altera_preco(Ingresso * ingresso, int qtdIngresso)
{
    int novoPreco;
    int i;
    for(i = 0; i < qtdIngresso; i++){
    printf("================================== \n");
    printf("Insira o novo valor para %s: \n", ingresso[i].atracao);
    scanf("%f", &novoPreco);
    ingresso[i].preco = novoPreco;
    }
}

void maiorEmenorPreco(Ingresso * ingresso, int qtdIngresso)
{
    int minIndex = 0, maxIndex = 0;
    for(int i = 1; i < qtdIngresso; i++) {
        if(ingresso[i].preco < ingresso[minIndex].preco) {
            minIndex = i;
        }
        if(ingresso[i].preco > ingresso[maxIndex].preco) {
            maxIndex = i;
        }
    }
    printf("Ingresso mais barato:\n");
    printf("%d", minIndex);//mudar aqui
    printf("Ingresso mais caro:\n");
    printf("%d", maxIndex);
    
}