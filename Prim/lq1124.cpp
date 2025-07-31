#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INFINITY LLONG_MAX/2
using namespace std;
struct Edge{
    long long cost=INFINITY;
    int go=0;
    Edge*next=nullptr;
    Edge(long long cost,int go,Edge*next){
        this->cost=cost;
        this->go=go;
        this->next=next;
    }
};
struct vertex{
    Edge*adjacent=nullptr;
};
int findmin(vector<int>S,vector<long long>dist,int N){
    int v=-1;
    long long cost=INFINITY;
    for(int i=1;i<=N;i++){
        if(S[i]==0&&dist[i]<cost){
            v=i;
            cost=dist[i];
        }
    }
    return v;
}
bool Prim(vector<vertex>&head,vector<long long>&dist,int N){
    vector<int>S(N+1,0);
    dist[1]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({dist[1],1});
    while(!pq.empty()){
        auto now=pq.top();
        long long cost=now.first;
        int v=now.second;
        if(cost==INFINITY)return false;
        S[v]=1;
        pq.pop();
        for(Edge*p=head[v].adjacent;p!=nullptr;p=p->next){
            int go=p->go;
            long long cost=p->cost;
            if(S[go]==0&&dist[go]>cost){
                dist[go]=cost;
                pq.push({cost,go});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(S[i]==0)return false;
    }
    return true;
}
int main(void){
    int N,M;
    cin>>N>>M;
    vector<vertex>head(N+1);
    for(int i=0;i<M;i++){
        int come,go;
        long long cost;
        cin>>come>>go>>cost;
        Edge*p1=new Edge(cost,go,head[come].adjacent);
        head[come].adjacent=p1;
        Edge*p2=new Edge(cost,come,head[go].adjacent);
        head[go].adjacent=p2;
    }
    vector<long long>ans(N+1,INFINITY);
    long long result=0;
    if(Prim(head,ans,N)){
        for(int i=1;i<=N;i++){
            result+=ans[i];
        }
        cout<<result<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
