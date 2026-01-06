#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>dp(n,vector<int>(3,0));
            dp[0][0]=-prices[0];//有股票
            dp[0][1]=0;//没股票且在冷冻期
            dp[0][2]=0;//没股票且不在冷冻期
            for(int i=1;i<n;i++){
                dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);//要不就是之前买的，要不就是今天买的，今天买的就说明今天可以买，所以从2转移来
                dp[i][1]=dp[i-1][0]+prices[i];//有股票才能卖，只能从0转移来
                dp[i][2]=max(dp[i-1][2],dp[i-1][1]);//前一天没股票且不买
            }
            return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
        }
    };