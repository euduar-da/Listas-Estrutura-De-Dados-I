#include <stdio.h>
//maneira de definir constantes em C
//#define TRUE 0
//#define FALSE 1


//int main(void){
  //  int resposta; 
   // printf("voce gosta de algoritmos? \n 0-True \n 1-False\n");
    //scanf("%d", &resposta);
     //   if(resposta == true){
       //     printf("Boa escolha! \n");
        //}
        //else if(resposta == false){
         //   printf("Que pena!");
        //}


//}

/*


//maneira de definir constantes usando enumeração

typedef enum bool{
    true,
    false
}Bool;

int main(void){
    Bool resposta; 
    printf("voce gosta de algoritmos? \n 0-True \n 1-False\n");
    scanf("%d", &resposta);
        if(resposta == true){
            printf("Boa escolha! \n");
        }
        else if(resposta == false){
            printf("Que pena!");
        }


}

*/

//questao um
typedef enum genero{
    masculino,
    feminino
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero_pessoa;
}Pessoa;


void getDados(Pessoa * pessoa){
    printf("Informe o nome: \n");
    scanf("%[^\n]", pessoa->nome);
    printf("informe a idade: \n");
    scanf("%d", &pessoa->idade);
    printf("informe o genero: \n 0-Masculino \n 1-Feminino");
    scanf("%d", &pessoa->genero_pessoa);
}

void imprimePessoa(Pessoa * pessoa){
    printf("nome: %s \n Idade: %d \n Genero: %s", pessoa ->nome, pessoa->idade, pessoa->genero_pessoa == masculino? "masculino" : "feminino"); 
    //se for falso imprima masculino, se for verdadeiro, imprima feminino
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    getDados(pessoa);
    imprimePessoa(pessoa);
    free(pessoa);



}