//implementa a função ingresso.h
#include <stdio.h>
#include <stdlib.h>
#include "ingresso.h"
//se quiser compilar direto aqui, colocar ingresso.c


int main(void) 
{
     int qtdIngresso = 3; //são possíveis 3 cadastros de ingressos
    Ingresso * ingresso = malloc (qtdIngresso * sizeof(Ingresso *));

      for(int i = 0; i < ingresso; i++) {
        preenche(&ingresso[i]);
    }

    for(int i = 0; i < ingresso; i++) {
        imprime(&ingresso[i]);
    };

    altera_preco(ingresso, qtdIngresso);

    imprime_menor_maior_preco(ingresso);

    free(ingresso);

    return 0;
}

void maiorEmenorPreco(Ingresso * ingresso, int qtdIngresso){
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
    imprime(&ingresso[minIndex]);
    printf("Ingresso mais caro:\n");
    imprime(&ingresso[maxIndex]);
    
}