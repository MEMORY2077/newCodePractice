#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            int maxnums=1;
            vector<int>dp(n,1);
            for(int i=1;i<n;i++){
                int temp=0;
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        temp=max(temp,dp[j]);
                    }
                }
                dp[i]=temp+1;
                maxnums=max(dp[i],maxnums);
            }
            return maxnums;
        }
        //[10,9,2,5,3,7,101,18]
    };