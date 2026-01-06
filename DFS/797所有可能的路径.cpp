#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>>ans;
            vector<int>path;
            path.push_back(0);
            n=graph.size();
            dfs(graph,ans,path,0);
        };
        bool dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>&path,int now){
            if(now==n-1){
                ans.push_back(path);
                return true;
            }
            for(int i=0;i<n-1;i++){
                if(now!=i&&graph[now][i]){
                    path.push_back(i);
                    dfs(graph,ans,path,i);
                    path.pop_back();
                }
            }
            return true;
        }
        int n=0;
    };