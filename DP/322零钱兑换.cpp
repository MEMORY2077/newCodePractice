#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            const int INF=0x3f3f3f3f;
            vector<int>dp(amount+1,INF);
            dp[0]=0;
            for(int money:coins){
                for(int j=money;j<=amount;j++){
                    if(dp[j-money]!=INF){
                        dp[j]=min(dp[j-money]+1,dp[j]);
                    }
                }
            }
            if(dp[amount]!=INF)return dp[amount];
            return -1;
        }
    };