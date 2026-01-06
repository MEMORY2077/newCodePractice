#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int maximum=0;
            int ans=0;
            int n=nums.size();
            vector<int>cnt(n);
            vector<int>dp(n);
            for(int i=0;i<n;i++){
                dp[i]=1;
                cnt[i]=1;
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        if(dp[j]+1>dp[i]){
                            dp[i]=dp[j]+1;
                            cnt[i]=cnt[j];
                        }
                        else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
                    }
                }
                if(dp[i]>maximum){
                    maximum=dp[i];
                    ans=cnt[i];
                }
                else if(dp[i]==maximum){
                    ans+=cnt[i];
                }
            }
            return ans;
        }
    };