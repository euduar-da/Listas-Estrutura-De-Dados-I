#include<stdio.h>

//Considere o trecho de código abaixo:
int main(void) {
int x, *p;
x = 100;
p = x;
printf("Valor de p = %d\t Valor de *p = %p", p, *p);
}

//a) advertência.
//b) a atribuição de x a p não foi feita da maneira correta.
//c) não, ocorreu a advertência citada no item acima.
//d) resolução abaixo:
int main(void) {
    int x;
    int *p;
x = 100;
p = &x;
    printf("Valor de p = %d\t Valor de *p = %p", p, *p);
}
//e) foi bem sucedida.