#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N=0;
    cin>>N;
    for(int _=0;_<N;_++){
        int mu,sieta,n;
        cin>>mu>>sieta>>n;
        int target=1000*(n-mu)/sieta;
        int lie=target%100;
        int hang=target/100;
        cout<<hang<<' '<<lie<<endl;
    }
}