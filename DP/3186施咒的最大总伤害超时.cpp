#include <bits/stdc++.h>
using namespace std;class Solution {
    public:
        long long maximumTotalDamage(vector<int>& power) {
            int n=power.size();
            //vector<int>dp(n,0);
            map<int,int>dp;
            int maxpower=0;
            for(int i=0;i<n;i++){
                dp[power[i]]+=power[i];
                maxpower=max(power[i],maxpower);
            }
            //if(dp.size()==1)return dp[maxpower];
            //dp[1]=max(dp[0],dp[1]);
            //if(dp.size()==2)return dp[1];
            //dp[2]=max(dp[1],dp[2]);
            //if(dp.size()==3)return dp[2];
            for(int i=0;i<=maxpower;i++){
                dp[i]=max({dp[i-3]+dp[i],dp[i-1],dp[i-2]});
            }
            return dp[maxpower];
        }
    };