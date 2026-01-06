#include <iostream>
using namespace std;
long long rumul(long long int a,long long int b){
    long long ans=0;
    while(a!=0){
        if(a%2==1){
            ans+=b;
        }
        a/=2;
        b*=2;
    }
    return ans;
}
long long rupowl2r(long long int a,long long int b,long long int m){
    long long int ans=1;
    for(int i=63;i>=0;i--){
        ans=(ans*ans)%m;
        if(b&(1LL<<i))ans=(ans*a)%m;
    }
    return ans;
}
long long rupowr2l(long long int a,long long int b,long long int m){
    long long int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
int main(void){
    int a,b;
    //cin>>a>>b;
    //cout<<"正确结果:"<<(long long)a*b<<endl;
    //cout<<"俄国农民乘法"<<rumul(a,b)<<endl;
    cout<<rupowl2r(2,10,7)<<endl;
    cout<<rupowr2l(2,10,7)<<endl;
}