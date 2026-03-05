#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>edges(n);
        int cc=ed.size();
        for(int i=0;i<cc;i++){
            //cout<<i<<endl;
            int u=ed[i][0];
            int v=ed[i][1];
            double cost=succProb[i];
            edges[u].emplace_back(v,cost);
            edges[v].emplace_back(u,cost);
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,less<>>pq;
        pq.push({1,start_node});
        set<int>S;
        vector<double>res(n,0);
        res[start_node]=1;
        while(!pq.empty()){
            auto [cost,u]=pq.top();
            pq.pop();
            if(u==end_node)return cost;
            if(!S.count(u)){
                S.insert(u);
                for(auto [v,next_cost]:edges[u]){
                    if(!S.count(v)){
                        res[v]=max(res[v],res[u]*next_cost);
                        pq.push({res[v],v});
                    }
                }
            }
        }
        return res[end_node];
    }
};