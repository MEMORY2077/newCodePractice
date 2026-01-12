#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long maximumTotalDamage(vector<int> power) {
            map<int,int>count;
            for(int p:power){
                count[p]++;
            }
            vector<pair<int,int>>vec={{INT_MIN,0}};
            for(auto p:count){
                vec.push_back(p);
            }
            int n=vec.size();
            vector<long long>dp(n,0);
            long long res=0;
            int j=1;
            for(int i=1;i<n;i++){
                while(j<i&&vec[j].first<vec[i].first-2){
                    res=max(res,dp[j]);
                    j++;
                }
                dp[i]=res+vec[i].first*vec[i].second;
            }
            long long ans=0;
            for(int i=1;i<n;i++){
                ans=max(ans,dp[i]);
            }
            return ans;
        }
    };
int main(void){
    Solution a;
    a.maximumTotalDamage({7,1,6,6});
    return 0;
}