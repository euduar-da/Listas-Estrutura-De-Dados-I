#include<stdio.h>

int main (){
        int x, y, *p;
        y = 0; //atribui valor 0 a Y;
        p = &y; //atribui o endereço de Y ao ponteiro;
        x = *p; 
        x = 4; //atribui valor 4 a x;
        (*p)++; //como o valor de y = 0 foi atribuído ao ponteiro, com o incremento o valor ficará 1; então y=1 e p=1
        --x; //já que x=4, com o desencremento, o valor passará a ser 3;
        (*p) += x;  //pelo fato do ponteiro e do y possuírem valor = 1 e estarem sendo somados com o valor de x, ambos ficarão com 4

      //logo, os valores serão: x = 3; y = 4 e p = 4
}