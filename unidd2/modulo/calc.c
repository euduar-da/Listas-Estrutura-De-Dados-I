#include "calc.h"

float soma(float * num1, float * num2){
    float result = 0;
    result = (float)(*num1) + (float)(*num2);

    return result;
}

float subtracao(float * num1, float * num2){
    float result = 0;
    result = (float) (*num1) - (float)(*num2);

    return result;
}

float multiplicacao(float * num1, float * num2){
    float result = 0;
    result = (float)(*num1) * (float)(*num2);

    return result;
}

float divisao(float * num1, float * num2){
    float result = 0;
    result = (float)(*num1) / (float)(*num2);

    return result;
}