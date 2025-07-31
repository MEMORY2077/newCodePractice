#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int F[30][30][30],G[30][30][30];
public:
    pair<int,int>dp(int n,int f,int s){
        if(F[n][f][s]){//已经算过的
            return {F[n][f][s],G[n][f][s]};
        }
        if(f+s==n+1){
            //f和s正好对抗
            return {1,1};
        }
        if(f+s>n+1){
            //f和s都在右侧,对称全换到左边
            tie(F[n][f][s],G[n][f][s])=dp(n,n+1-s,n+1-f);
            return {F[n][f][s],G[n][f][s]};
        }
        int earlist=INT_MAX;
        int latest=INT_MIN;
        int n_half=(n+1)/2;
        if(s<=n_half){
            //s在左半部分or中间
            for(int i=0;i<f;i++){
                for(int j=0;j<s-f;j++){
                    auto [x,y]=dp(n_half,i+1,i+j+2);
                    earlist=min(earlist,x);
                    latest=max(latest,y);
                }
            }
        }
        else{
            //s在右边
            int sp=n+1-s;//和s对抗的s'，s'必须输
            int mid=(n-2*sp+1)/2;
            for(int i=0;i<f;i++){
                for(int j=0;j<sp-f;j++){
                    auto[x,y]=dp(n_half,i+1,i+j+mid+2);
                    earlist=min(earlist,x);
                    latest=max(latest,y);
                }
            }
        }
        return {F[n][f][s]=earlist+1,G[n][f][s]=latest+1};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F,0,sizeof(F));
        memset(G,0,sizeof(G));
        if(firstPlayer>secondPlayer){
            swap(firstPlayer,secondPlayer);
        }
        auto [earlist,latest]=dp(n,firstPlayer,secondPlayer);
        return {earlist,latest};
    }

};