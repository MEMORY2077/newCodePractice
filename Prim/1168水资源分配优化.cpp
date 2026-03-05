#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<pair<int,int>>>edges(n+1);
        for(int i=0;i<n;i++){
            edges[0].emplace_back(i+1,wells[i]);
            edges[i+1].emplace_back(0,wells[i]);
        }
        for(auto pipe:pipes){
            int v=pipe[0];
            int u=pipe[1];
            int cost=pipe[2];
            edges[v].emplace_back(u,cost);
            edges[u].emplace_back(v,cost);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        int ans=0;
        unordered_set<int>S;
        while(!pq.empty()){
            auto [cost,city]=pq.top();
            pq.pop();
            if(S.find(city)==S.end()){
                S.insert(city);
                ans+=cost;
                for(const auto&[next_city,next_cost]:edges[city]){
                    pq.push({next_cost,next_city});
                }
            }
        }
        return S.size()==n+1?ans:-1;
    }
};