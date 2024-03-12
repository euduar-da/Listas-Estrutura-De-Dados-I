#include<stdio.h>

// Qual será a saída exibida pelo programa a seguir:
int main(){
 int a, b, c, d;
 int *p1;
 int *p2 = &a;
 int *p3 = &c;
 p1 = p2;
 *p2 = 10;
 b = 20;
 int **pp;
 pp = &p1;
 *p3 = **pp;
 int *p4 = &d;
 *p4 = b + (*p1)++;
 printf("%d\t%d\t%d\t%d\n", a, b, c, d);
 return 0;
}
// a saída será: a=10; b=20 c=10; d=3o.