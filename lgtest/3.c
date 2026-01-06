#include <stdio.h>
int main(void){
    int L,R,M;
    scanf("%d%d%d",&L,&R,&M);
    int count=0;
    for(int i=L;i<=R;i++){
        if((i*i-1>=M||i*i-1==0)&&(i*i-1)%M==0)count++;
    }
    printf("%d",count);
    return 0;
}