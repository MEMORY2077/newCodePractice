#include <vector>
using namespace std;
class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            int m=coins.size();
            int n=amount;
            vector<vector<int>>dp(m,vector<int>(n+1,0));
            for(int i=0;i<=n;i++){
                if(i%coins[0]==0)dp[0][i]=1;
            }
            for(int i=0;i<m;i++){
                dp[i][0]=1;
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=dp[i-1][j];
                    if(j-coins[i]>=0){
                        dp[i][j]+=dp[i][j-coins[i]];
                    }
                }
            }
            return dp[m-1][n];
        }
    };  