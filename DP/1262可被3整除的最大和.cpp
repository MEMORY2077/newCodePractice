#include <vector>
#include <limits.h>
using namespace std;
class Solution {
    public:
        int maxSumDivThree(vector<int>& nums) {
            vector<int>dp={0,INT_MIN,INT_MIN};
            for(int num:nums){
                vector<int>g=dp;
                for(int i=0;i<3;i++){
                    g[(i+num%3)%3]=max(g[(i+num%3)%3],dp[i]+num);
                }
                dp=g;
            }
            return dp[0];
        }
    };