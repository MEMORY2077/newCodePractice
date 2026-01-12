#include<iostream>
using namespace std;
int main(void){
    int N=0;
    cin>>N;
    int ans=0;
    for(int n=1;n<=N;n++){
        int now=n;
        bool odd=true;
        while(now!=0){
            int t=now%10;
            bool flag=true;
            if(t%2==0){
                if(odd){
                    ans--;
                    break;
                }
            }
            else{
                if(!odd){
                    ans--;
                    break;
                }
            }  
            if(odd){
                odd=false;
            }
            else odd=true;
            now/=10;
        }
        ans++;
    }
    cout<<ans<<endl;
    return true;
}