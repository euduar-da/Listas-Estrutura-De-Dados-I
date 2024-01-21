#include <stdio.h>
#include <stdlib.h>

void perguntas();
void porct_Fem();
void masc_ngostaram();


int main(void){
    int continuar_Respondendo;
    int pessoas_Entrevistadas = 1;
    int * entrevistadosP = &pessoas_Entrevistadas;
    int * perguntaUm = (int*) malloc( (*entrevistadosP) * sizeof(int));
    int * perguntaDois = (int*) malloc( (*entrevistadosP) * sizeof(int));

    perguntas(perguntaUm, perguntaDois, entrevistadosP); // não coloca o * aqui

    printf("Deseja continuar respondendo a pesquisa? 1- Sim \\ 2- Nao \n");
    scanf("%d", &continuar_Respondendo);


    while (continuar_Respondendo != 2){
         
          ++(*entrevistadosP);
           int * perguntaUm = (int*) realloc(perguntaUm, (*entrevistadosP) * sizeof(int)); // realoca o tamanho do vetor para a nova quantidade de pessoas entrevistadas
           int * perguntaDois = (int*) realloc(perguntaDois, (*entrevistadosP) * sizeof(int));
           
           perguntas(perguntaUm, perguntaDois, entrevistadosP);
          

             printf("continuar com a pesquisa? 1. Sim / 2. Nao \n");
            scanf("%d", &continuar_Respondendo);
           perguntas(perguntaUm, perguntaDois, entrevistadosP);
      
    }
    
        printf("Os resultados obtidos foram: \n");
        porct_Fem(perguntaUm, perguntaDois, &pessoas_Entrevistadas);
        masc_ngostaram(perguntaUm, perguntaDois, &pessoas_Entrevistadas);
    

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

void porct_Fem(int * perguntaUm, int * perguntaDois, int * entrevistadosP){
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


void masc_ngostaram(int * perguntaUm, int * perguntaDois, int * entrevistadosP){
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