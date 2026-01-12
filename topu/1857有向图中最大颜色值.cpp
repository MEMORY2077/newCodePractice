#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int n=colors.size();
            vector<vector<int>>g(n);
            vector<int>indeg(n,0);
            for(auto edge:edges){
                indeg[edge[1]]++;//统计入度
                g[edge[0]].push_back(edge[1]);//构建邻接表
            }
            int count=0;//不够n就有环
            vector<vector<int>>dp(n,vector<int>(26,0));
            queue<int>q;
            for(int i=0;i<n;i++){
                if(!indeg[i])q.push(i);//结点i入度为0,可以启动
            }
            while(!q.empty()){
                count++;
                int u=q.front();
                q.pop();
                dp[u][colors[u]-'a']++;
                for(int v:g[u]){
                    if(--indeg[v]==0){
                        q.push(v);
                    }
                    for(int c=0;c<26;c++){
                        dp[v][c]=max(dp[v][c],dp[u][c]);
                    }
                }
            }
            if(count!=n)return -1;
            int ans=0;
            for(int i=0;i<n;i++){
                for (int j=0;j<26;j++){
                    ans=max(ans,dp[i][j]);
                }
            }
            return ans;
        }   
    };