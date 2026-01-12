#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestArithSeqLength(vector<int>& nums) {
            int m=INT_MIN;
            for(int now:nums){
                m=max(now,m);
            }
            int ans=0;
            for(int difference=-m;difference<=m;difference++){
                unordered_map<int,int>dp;
                for(int v:nums){
                    dp[v]=dp[v-difference]+1;
                    ans=max(dp[v],ans);
                }
            }
            return ans;
        }
    };