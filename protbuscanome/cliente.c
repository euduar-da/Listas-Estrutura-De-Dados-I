// Bibliotecas usadas aqui:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct cliente
{
    char nome[50];
    char endereco[70];
    int id;
};
// Como utilizo essa função para contar e alocar, preciso receber o array, então:
struct cliente *contaClientes(int *qtdC)
{
    // Declarando variáveis:
    int tamanho = 0;
    char linha[101];
    FILE *arquivo;

    arquivo = fopen("DataBase.txt", "r");

    // No arquivo de texto, uma linha representa um cliente. Então contamos:
    while (fscanf(arquivo, "%[^\n]\n", linha) != EOF)
    {
        tamanho++;
    }

    // Fechando...
    fclose(arquivo);

    // Aloca memória para o número de clientes
    struct cliente *clientes = malloc(tamanho * sizeof(struct cliente));

    // Retorna o número de clientes através do ponteiro qtdC
    *qtdC = tamanho;

    // Retorna o array para que possa ser utilizado em outros lugares do código:
    return clientes;
}

// Função para leitura e coleta dos dados:
void coletaDados(struct cliente *clientes, int qtdC)
{
    // Declarando as variáveis:
    int i = 0;

    FILE *dados;
    dados = fopen("DataBase.txt", "r");

    // Criando um loop até o fim do arquivo...
    while (i < qtdC)
    {
        fscanf(dados, " %[^\t]\t %[^\t]\t%d", clientes[i].nome, clientes[i].endereco, &clientes[i].id);
        i++;
    }

    // Fechando...
    fclose(dados);
}
// Função para mostrar dados (apenas para fins de verificação):
void mostrarDados(struct cliente *Cliente, int qtdClientes)
{
    int j;
    for (j = 0; j < qtdClientes; j++)
    {
        printf("Nome: %s, Endereço: %s, ID: %d\n", Cliente[j].nome, Cliente[j].endereco, Cliente[j].id);
    }
};

int comparaID(const void * pa, const void * pb){
    const struct cliente * p1 = pa;
    const struct cliente * p2 = pb;
    return p1->id - p2->id;
}

void ordenaId(struct cliente *Cliente, int qtdClientes){
    qsort(Cliente, qtdClientes, sizeof(struct cliente), comparaID);
}

int comparaNome(const void * pa, const void * pb){
    const struct cliente * p1 = pa;
    const struct cliente * p2 = pb;
    return strcmp(p1->nome, p2->nome);
}

void ordenaNome(struct cliente *Cliente, int qtdClientes){
    qsort(Cliente, qtdClientes, sizeof(struct cliente), comparaNome);
}

//coloqeui aqui
void buscaBinariaNome(struct cliente *clientes, int qtdClientes)
{
    ordenaNome(clientes, qtdClientes);
    char nomeDesejado[50]; //vai armazenar o nome que o usário deseja buscar
    int min = 0; //parte iniical do vetor
    int max = qtdClientes - 1; //fim do vetor
    int meio = 0;
    printf("Digite o nome desejado: \n");
    scanf(" %[^\n]", nomeDesejado); //está recebendo o nome que deve ser buscado

    while(min <= max ) //enquanto o valor inicial do vetor for menor ou igual ao final, vai realizar a operação até que se encontre o nome desejadoo
    {
        meio = (min+max)/2;
        
        int comparacao = strcmp(clientes[meio].nome, nomeDesejado); //realiza a comparação das strings
            if(comparacao == 0)
            {
                printf("================================\n");
                printf("Nome: %s\n", clientes[meio].nome);
                printf("Endereço: %s \n", clientes[meio].endereco);
                printf("ID: %d\n", clientes[meio].id);
                printf("================================\n");
                return;

            } 
            else if(comparacao > 0) 
            { 
                max = meio -1;
           }else //se o nome buscado é menor que o do meio do vetor
            {
                min = meio + 1; //atualiza o índice para a parte que é superior do vetor
            }
             //caso o nome não seja encontrado, vai indicar que é inexistente
    }
               
        //caso o nome não seja encontrado, vai indicar que é inexistente
        printf("cliente não encontrado\n");
}
