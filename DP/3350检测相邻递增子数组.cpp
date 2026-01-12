#include <vector>
#include <algorithm>
using std::vector,std::max,std::min;
class Solution {
    public:
        int maxIncreasingSubarrays(vector<int>& nums) {
            int n=nums.size();
            int length=0;
            vector<int>dp(n,1);
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1])dp[i]=dp[i-1]+1;
                else dp[i]=1;
                //length=max(dp[i],length);                
            }
            for(int i=0;i<n;i++){
                //cout<<i<<":";
                //cout<<dp[i]<<' ';
                if(i-(dp[i]+1)/2>=0)length=max(length,min(dp[i],dp[i-(dp[i]+1)/2]));
                if(i-dp[i]>=0)length=max(length,min(dp[i],dp[i-dp[i]]));
            }
            return length;
        }
    };