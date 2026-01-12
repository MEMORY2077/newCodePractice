#include <stdio.h>
void abc(){
    char*s="%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n%x\n";
    int a=0x11223344;
    int b=0x00000001;
    int c=0x00000002;
    printf("0x%s\n0x%s\n0x%s\n",&a,&b,&c);
    printf(s);
}
int main(void){
    //c=a+b;
    abc();
    return 0;
}