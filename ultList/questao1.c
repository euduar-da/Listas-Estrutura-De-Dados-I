#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ingresso{
    float preco;
    char local[20];
    char atracao[20];
}Ingresso;


void preenche (Ingresso* ingresso){
    printf("insira o valor do ingresso: \n");
    scanf("%f", &ingresso->preco);
    printf("insira o local: \n");
    scanf(" %[^\n]", ingresso->local);
    printf("insira qual a atracao: \n");
    scanf(" %[^\n]", ingresso->atracao);
}


void imprime (Ingresso* ingresso){
    printf("=================================\n");
    printf("valor: %.2f \n", ingresso->preco);
    printf("local: %s \n", ingresso->local);
    printf("atracao: %s \n", ingresso->atracao);
   

}

void altera_preco(Ingresso * ingresso, float preco){
    printf("================================== \n");
    printf("Insira o novo valor: \n");
    scanf("%f", ingresso->preco);
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
int main(void){
    int qtdIngresso = 3; //3 porque dá para comparar o maior e menor preço sme precisasr de vários cadastros
    Ingresso * ingresso = malloc (qtdIngresso * sizeof(Ingresso));

      for(int i = 0; i < ingresso; i++) {
        preenche(&ingresso[i]);
    }

    for(int i = 0; i < ingresso; i++) {
        imprime(&ingresso[i]);
    }

    altera_preco(ingresso, preco);

    imprime_menor_maior_preco(ingresso);

    preenche(ingresso);
    imprime(ingresso);

    return 0;
}


