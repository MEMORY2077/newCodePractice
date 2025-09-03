#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
    public:
        const int INIFINITY=0x3f3f3f3f;
        int numSquares(int n) {
            int m=int(sqrt(n));
            vector<vector<int>>dp(m+1,vector<int>(n+1,INIFINITY));
            for(int i=0;i<=m;i++){
                dp[i][0]=0;
            }
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=dp[i-1][j];
                    if(j-i*i>=0){
                        dp[i][j]=min(dp[i][j],dp[i][j-i*i]+1);
                    }
                }
            }
            return dp[m][n];
        }
    };