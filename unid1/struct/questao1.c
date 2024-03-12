#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct Funcionario
{
    char nome[50];
    char cargo[25];
    int indentificador;
    float salario;
    

};

void cadastroFuncionario(struct Funcionario * funcionario);
void imprimirDados(struct Funcionario * funcionario);
void alterarSalario(struct Funcionario * funcionario);

int main (void){
    int i = 0;
    struct Funcionario * funcionario = malloc(3 *sizeof(struct Funcionario));
  if (funcionario == NULL){
        exit(1);
    }
 for (i = 0; i <3; i++){
        cadastroFuncionario(&funcionario[i]); //assim a função ta pegando os elementos um por um, colaborador[0], depois o colaborafor[1], ...
    }

    for (i = 0; i < 3; i++){
        imprimirDados(&funcionario[i]);  
    }

    for (i = 0; i < 3; i++){
        alterarSalario(&funcionario[i]);  
    }

    maiorSalario(funcionario); //aqui ele está pegando o array completo e fará a "filtragem" dentro da funçao maiorSalario
    
    return 0;
}
    


void cadastroFuncionario(struct Funcionario * funcionario)
{
    printf("insira o nome do colaborador: \n");
    scanf (" %[^\n]", funcionario->nome);
    printf("insira o cargo \n");
    scanf (" %[^\n]", funcionario->cargo);
    printf("insira o identificador do colaborador \n");
    scanf("%d", &funcionario->indentificador);
    printf("por fim, insira o salario \n");
    scanf ("%f", &funcionario->salario);
};

void imprimirDados(struct Funcionario * funcionario)
{
    printf("Nome: %s \n", funcionario->nome);
    printf("Cargo: %s \n", funcionario->cargo);
    printf("Identificador: %d \n", funcionario->indentificador);
    printf("Salario: %f \n", funcionario->salario);
};

void alterarSalario(struct Funcionario * funcionario)

{
   printf("digite o novo salário do funcionario: \n");
   scanf("%f", &funcionario->salario);
};

//void menuOp(struct Funcionario * funcionario){
  //  int op;
   // int op2;
    // printf("Voce deseja: \n");
   // printf("1- cadastrar funcionario \n");
   // printf("2- exibir dados do funcionario \n");

//    scanf("%d", &op);

//    if (op == 1){
  //      cadastroFuncionario(funcionario);

    //    printf("deseja imprimir os dados do funcionario? 1. s/ 2. n \n");
      //  scanf(" %d", &op2);
        //if(op2 == 1){
          //  imprimirDados(funcionario);
        //}

    //}

//}