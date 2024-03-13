//implementa a função ingresso.h
#include <stdio.h>
#include <stdlib.h>
#include "ingresso.h"
//se quiser compilar direto aqui, colocar ingresso.c


int main(void) 
{
     int qtdIngresso = 3; //são possíveis 3 cadastros de ingressos
    Ingresso * ingresso = (Ingresso*) malloc (qtdIngresso * sizeof(Ingresso *));

   preenche(ingresso, qtdIngresso);

   imprime(ingresso, qtdIngresso);

    altera_preco(ingresso, qtdIngresso);

    maiorEmenorPreco(ingresso, qtdIngresso);

    free(ingresso);

    return 0;
}

