#include <vector>
using namespace std;
class Solution {
    private:
        int time=0;
        vector<int>dfn,low;
        vector<vector<int>>adj;
        vector<vector<int>>ans;
        void Tarjan(int u,int fa){
            dfn[u]=low[u]=++time;
            for(int v:adj[u]){
                if(v==fa)continue;
                if(!dfn[v]){
                    Tarjan(v,u);
                    low[u]=min(low[v],low[u]);
                    if(low[v]>dfn[u]){
                        ans.push_back({u,v});
                    }
                }
                else{
                    low[u]=min(low[v],low[u]);
                }
            }
            return;
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            dfn.resize(n);
            low.resize(n);
            adj.resize(n);
            for(vector<int>edge:connections){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            for(int i=0;i<n;i++){
                Tarjan(i,-1);
            }
            return ans;
        }
    };