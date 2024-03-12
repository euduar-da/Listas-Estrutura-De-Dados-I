
#include "calc.h"

int main(void){
    float num1 = 0;
    float num2 = 0;

    printf("digite o num1: ");
    scanf("%f", &num1);
    printf("digite o num2: ");
    scanf("%f", &num2);

    printf("soma: %.2f\n", soma(&num1, &num2));
    printf("subtracao: %.2f\n", subtracao(&num1, &num2));
    printf("multiplicacao: %.2f\n", multiplicacao(&num1, &num2));
    printf("divisao: %.2f\n", divisao(&num1, &num2));

    return 0;
}