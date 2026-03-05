#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0x3f3f3f3f);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int mx=nums[i];
            for(int j=0;j<=mx&&i+j<n;j++){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};