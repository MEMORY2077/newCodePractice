#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void Floyd(vector<vector<long long>>&map,int N,vector<vector<long long>>&dist){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
            }
        }
    }
}
int main()
{
    int N,M,Q;
    cin>>N>>M>>Q;
    vector<vector<long long>>map(N+1,vector<long long>(N+1,LLONG_MAX/2));
    for(int i=0;i<M;i++){
        int come,go;
        long long cost;
        cin>>come>>go>>cost;
        if(cost<map[come][go]){
            map[come][go]=cost;
        }
        if(cost<map[go][come]){
            map[go][come]=cost;
        }

    }
    vector<vector<long long>>dist=map;
    Floyd(map,N,dist);
    for(int i=0;i<Q;i++){
        int come,go;
        cin>>come>>go;
        if(come==go){
            cout<<0<<endl;
        }
        else if(dist[come][go]<LLONG_MAX/2){
            cout<<dist[come][go]<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}