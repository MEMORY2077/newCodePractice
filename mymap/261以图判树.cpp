#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n!=edges.size())return false;
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int>visited;
        if(dfs(0,-1,adj,visited))return false;
        if(visited.size()==n)return true;
        return false;
    }
    bool dfs(int now,int parents,const vector<vector<int>>&adj,unordered_set<int>&visited){
        if(visited.count(now))return false;
        visited.emplace(now);
        for(int next:adj[now]){
            if(next==parents)continue;
            if(visited.count(next))return false;
            if(!dfs(next,now,adj,visited))return false;
        }
        return true;
    }
};