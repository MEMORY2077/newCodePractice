#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<pair<int,int>>>e(n);
            for(auto edge:connections){
                e[edge[0]].push_back({edge[1],1});
                e[edge[1]].push_back({edge[0],0});
            }
            return dfs(0,-1,e);
        }
        int dfs(int x,int parent,vector<vector<pair<int,int>>>&e){
            int res=0;
            for(auto edge:e[x]){
                if(edge.first==parent){
                    continue;
                }
                res+=(edge.second+dfs(edge.first,x,e));
            }
            return res;
        }
    };