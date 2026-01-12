#include <vector>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int countGoodStrings(int low, int high, int zero, int one) {
            vector<int>dp(high+1,0);
            dp[0]=1;
            for(int i=1;i<=high;i++){
                if(i-zero>=0)dp[i]+=(dp[i-zero])%MOD;
                if(i-one>=0)dp[i]+=(dp[i-one])%MOD;
            }
            int ans=0;
            for(int i=low;i<=high;i++){
                ans=(ans+(long long)dp[i])%MOD;
            }
            return ans;
        }
    };