#include <iostream>
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        int result=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            result=max(dp[i],result);
        }
        return result;
    }
};