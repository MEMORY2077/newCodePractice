#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int>dp(nums.size(),1);
            int maximum=1;
            int n=nums.size();
            for(int i=1;i<n;i++){
                int temp=0;
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i]){
                        temp=max(temp,dp[j]);
                    }
                }
                dp[i]=dp[i]+temp;
                maximum=max(dp[i],maximum);
            }
            return maximum;
        }
        //[10,9,2,5,3,7,101,18]
    };