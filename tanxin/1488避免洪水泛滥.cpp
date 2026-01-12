#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> avoidFlood(vector<int>& rains) {
            int n=rains.size();
            vector<int>ans(n,-1);
            set<int>dry;
            unordered_map<int,int>full_day;
            for(int i=0;i<n;i++){
                int lake=rains[i];
                if(lake==0){
                    ans[i]=1;
                    dry.emplace(i);
                    continue;
                }
                if(full_day.find(lake)!=full_day.end()){
                    int j=full_day[lake];
                    auto it=dry.upper_bound(j);
                    if(it==dry.end()){
                        return {};
                    }
                    ans[*it]=lake;
                    dry.erase(it);
                }
                full_day[lake]=i;
            }
            return ans;
        }
    };