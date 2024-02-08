/*Definição de um novo tipo : Ingresso*/

//cria uma estrutura do tipo ingresso

typedef struct ingresso Ingresso;

/*Função que realiza o preenchimeeto das informações*/
void preenche (Ingresso * ingresso, int qtdIngresso);

/*Função que imprime os dados do ingresso*/
void imprime(Ingresso * ingresso, int qtdIngresso);

/*Função que realiza alteração no valor dos ingressos*/
void altera_preco(Ingresso * ingresso, int qtdIngresso);

/*Função que compara os valores dos ingressos existentes,
retorna qual o mais barato e o mais caro*/
void maiorEmenorPreco(Ingresso * ingresso, int qtdIngresso);