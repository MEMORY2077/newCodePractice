#include <stdio.h>
int main(void){
    int x=100;
    int a=0;
    /*
    if(x)a=1;
    else a=100;
    printf("%d",a);
    return 0;*/
    //int c=128;
    //printf("%b",c);
    //a=(1&(128-(x!=0)))+(100&(128-(x==0)));
    a=1+(99&(128-(x==0)));
    //a=1+(99&!x);
    printf("%d",a);
    return 0;
}