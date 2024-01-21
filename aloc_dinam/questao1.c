#include <stdio.h>
#include <stdlib.h>

void perguntas();
void porctFem();
void mascngostaram();


int main(void){
    int continuarRespondendo;
    int pessoasEntrevistadas = 1;
    int * entrevistadosP = &pessoasEntrevistadas;
    int * perguntaUm = (int*) malloc( (*entrevistadosP) * sizeof(int));
    int * perguntaDois = (int*) malloc( (*entrevistadosP) * sizeof(int));

    perguntas(perguntaUm, perguntaDois, entrevistadosP); // não coloca o * aqui

    printf("Deseja continuar respondendo a pesquisa? 1- Sim \\ 2- Nao \n");
    scanf("%d", &continuarRespondendo);


    while (continuarRespondendo != 2){
         
          ++(*entrevistadosP);
           int * perguntaUm = (int*) realloc(perguntaUm, (*entrevistadosP) * sizeof(int)); // realoca o tamanho do vetor para a nova quantidade de pessoas entrevistadas
           int * perguntaDois = (int*) realloc(perguntaDois, (*entrevistadosP) * sizeof(int));
           
           perguntas(perguntaUm, perguntaDois, entrevistadosP);
          

             printf("continuar com a pesquisa? 1. Sim / 2. Nao \n");
            scanf("%d", &continuarRespondendo);
           perguntas(perguntaUm, perguntaDois, entrevistadosP);
      
    }
    
        printf("Os resultados obtidos foram: \n");
        porctFem(perguntaUm, perguntaDois, &pessoasEntrevistadas);
        masc_ngostaram(perguntaUm, perguntaDois, &pessoasEntrevistadas);
    

    return(0);
}

void perguntas(int * perguntaUm, int * perguntaDois, int * entrevistadosP){
    int i = *entrevistadosP - 1;
    printf("Selecione qual o seu sexo: 1- Feminino \\ 2- Masculino \n");
    scanf("%d", &perguntaUm[i]);
    printf("Qual sua opiniao sobre o produto? 1- Gostei \\ 2- Nao gostei \n");
    scanf("%d", &perguntaDois[i]);
    i++;

}

void porctFem(int * perguntaUm, int * perguntaDois, int * entrevistadosP){
    int i, qtd = 0;
    float porct;

    for (i = 0; i <(*entrevistadosP); i++){
        if (perguntaUm[i] == 1){
            if(perguntaDois[i] == 1){
                qtd++;
            }
        }
    }
    porct = (100 * qtd) / (*entrevistadosP); //calculo da porcentagem 
    printf("Dos entrevistados, a quantidade de mulheres que gostaram do produto e de %.2f \n", porct);
}


void mascngostaram(int * perguntaUm, int * perguntaDois, int * entrevistadosP){
    int i, qtd = 0;
    float porct;

    for (i = 0; i <(*entrevistadosP); i++){
        if (perguntaUm[i] == 2){
            if(perguntaDois[i] == 2){
                qtd++;
            }
        }
    }
    porct = (100 * qtd) / (*entrevistadosP); //calculo da porcentagem 
    printf("Dos entrevistados, a quantidade de homens que nao gostaram do produto e de %.2f \n", porct);
}