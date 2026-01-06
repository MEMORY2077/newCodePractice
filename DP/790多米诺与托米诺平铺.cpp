#include <vector>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int numTilings(int n) {
            if(n==1)return 1;
            vector<vector<int>>dp(n+1,vector<int>(4,0));
            dp[1][0]=1;
            dp[1][1]=1;
            for(int i=2;i<=n;i++){
                dp[i][0]=dp[i-1][1];
                for(int j=0;j<4;j++){
                    dp[i][1]=(dp[i][1]+dp[i-1][j])%MOD;
                }
                dp[i][2]=(dp[i-1][0]+dp[i-1][3])%MOD;
                dp[i][3]=(dp[i-1][0]+dp[i-1][2])%MOD;
            }
            return dp[n][1];
        }
    };