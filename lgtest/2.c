#include <stdio.h>
#include <math.h>
int main(void){
    float V0,E,a;
    scanf("%f%f%f",&V0,&E,&a);
    float k=sqrt(V0-E);
    float T=exp((-2)*k*a);
    printf("%.4f",T);
    return 0;
}