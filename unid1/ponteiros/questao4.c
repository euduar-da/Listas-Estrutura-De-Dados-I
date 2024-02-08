#include<stdio.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro){

*perimetro = 6 * l;
*area = (3*pow(l,2)*sqrt(3))/2;

printf("O perimetro e: %.2f \n", *perimetro ); //coloca o * para imprimir o valor, se colocar sem, imprime o local da memória
printf("A area e: %.2f \n", *area); //coloca o * para imprimir o valor, se colocar sem, imprime o local da memória
}

int main(){
    float al;
    float *ar;
    float *ap;
    printf("informe o valor do lado(l): \n");
       scanf("%f", &al);
    calcula_hexagono(al, &ar, &ap); //coloca o & para o ponteiro receber o valor
    return 0;
}