#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    static const int MOD=1000000007;
    vector<int>pp;
    int numberOfWays(int n, int x) {
        pp=vector<int>(n+1,0);
        for(int i=0;i<=n;i++){
            pp[i]=(long long)pow(i,x)%MOD;
            }
            vector<vector<int>>dp(n+1,vector<int>(n+1,0));
            dp[0][0]=1;
            for(int i=1;i<=n;i++){
                long long now=pow(i,x);
                for(int j=0;j<=n;j++){
                    dp[i][j]=dp[i-1][j];
                    if(j>=now){
                        dp[i][j]=(dp[i-1][j]+dp[i-1][j-now])%MOD;
                    }
                }
            }
        return dp[n][n];
    }
    int ans;
};