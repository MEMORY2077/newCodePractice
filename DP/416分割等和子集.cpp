#include <vector>
#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum=0;
            for(int x:nums){
                sum+=x;
            }
            if(sum%2!=0)return false;
            int n=nums.size();
            int m=sum/2;
            vector<vector<int>>dp(nums.size(),vector<int>(m+1,0));
            for(int i=nums[0];i<=m;i++){
                dp[0][i]=nums[0];
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<=m;j++){
                    dp[i][j]=dp[i-1][j];
                    if(j>nums[i]){
                        dp[i][j]=max(dp[i][j],dp[i-1][j-nums[i]]+nums[i]);
                    }
                }
            }
            if(dp[n-1][m]==m)return true;
            return false;
        }
    };