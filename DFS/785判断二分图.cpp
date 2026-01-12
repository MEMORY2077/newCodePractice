#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n=graph.size();
            visited=vector<int>(n,0);
            int now=1;
            for(int i=0;i<n;i++){
                if(visited[i]==0){
                    if(!dfs(graph,i,now))return false;
                }
            }
            return true;
        }
        bool dfs(vector<vector<int>>&graph,int x,int now){
            visited[x]=now;
            for(int next:graph[x]){
                if(visited[next]==0){
                    if(!dfs(graph,next,-now))return false;
                }
                else if(visited[next]==visited[x])return false;
            }
            return true;
        }
        vector<int>visited;
    };