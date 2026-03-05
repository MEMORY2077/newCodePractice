#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>edges(n+1);
        for(auto connection:connections){
            int a=connection[0];
            int b=connection[1];
            int c=connection[2];
            edges[a].emplace_back(b,c);
            edges[b].emplace_back(a,c);
        }
        unordered_set<int>S;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,1});
        int ans=0;
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
        return S.size()==n?ans:-1;
    }
};