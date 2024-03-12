#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getQtdNumeros(FILE * entrada, int * qtdNumeros);
void getDados(FILE * entrada, int qtdNumeros, int * numeros);
void maiorMenor(int qtdNumeros, int * numeros, int * maior, int * menor);
void calculaMedia(int * numeros, int qtdNumeros,  float * media);
void escreveDados(FILE * saida, int * numeros, float media, int maior, int menor);

int main(void){
    FILE * entrada = fopen("entrada_q2.txt", "r");
    int qtdNumeros = 0;
    int maior = 0;
    int menor = 0;
    float media = 0.0;

    getQtdNumeros(entrada, &qtdNumeros);
    rewind(entrada);    

    int * numeros = malloc(qtdNumeros * sizeof(int));
    getDados(entrada, qtdNumeros, numeros);
    fclose(entrada);

    maiorMenor(qtdNumeros, numeros, &maior, &menor);

    calculaMedia(numeros, qtdNumeros, &media);

    FILE * saida = fopen("saidaq2.txt", "w");
    
    escreveDados(saida, numeros, media, maior, menor);

    fclose(saida);
    free(numeros);

    return 0;
}


void getQtdNumeros(FILE * entrada, int * qtdNumeros){
    int c;
    while( (c = fgetc(entrada)) != EOF){ //enquanto receber caractere diferente de EOF (end of file)
        if(c == '\n'){
            (*qtdNumeros)++;
        }
    }

    (*qtdNumeros)++; 
}

void getDados(FILE * entrada, int qtdNumeros, int * numeros){
    int i;
    for(i = 0; i < qtdNumeros; i++){
        fscanf(entrada, "%d", &numeros[i]);
    }
}

void maiorMenor(int qtdNumeros, int * numeros, int * maior, int * menor){ 
    int i;

    for ( i = 1; i < qtdNumeros; i++){
        if ( numeros[i] < numeros[*(menor)]){
            *(menor) = i;
        }else if (numeros[i] > numeros[*(maior)]){
           *(maior) = i;
        }
    }   
}

void calculaMedia(int * numeros, int qtdNumeros,  float * media){
    int i;
    int soma = 0;
    for (i = 0; i < qtdNumeros; i++){
        soma +=  numeros[i];
    }   
    *(media) = (float)soma / qtdNumeros;
}

void escreveDados(FILE * saida, int * numeros, float media, int maior, int menor){
    fprintf(saida, "maior: %d\nmenor: %d\nmedia: %.2f", numeros[maior], numeros[menor], media);
}