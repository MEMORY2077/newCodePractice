#include <vector>
#include <algorithm>
//我猜是状态机dp
using namespace std;
class Solution {
    public:
        long long maximumProfit(vector<int>& prices, int k) {
            int n=prices.size();
            vector<vector<vector<long long>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,0)));
            //dp[i][j][k]
            for(int i=0;i<=k;i++){
                dp[0][i][1]=-prices[0];//第0天所有次交易的持有状态都是-prices[0];
            }
            for(int i=1;i<n;i++){
                //天数遍历
                for(int j=0;j<=k;j++){
                    //交易次数遍历
                    //当前没有股票状态，可能是之前买了今天卖出了，交易次数应该比之前多一次，或者是昨天没有，今天也没买
                    if(j>=1)dp[i][j][0]=max(dp[i-1][j-1][1]+prices[i],dp[i-1][j][0]);
                    else dp[i][j][0]=dp[i-1][j][0];
                    //当前有股票状态，可能是之前买了今天没卖，或者是今天刚买的
                    dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-prices[i]);
                }
            }
            //最后一天，交易k次，没股票
            return dp[n-1][k][0];
        }
    };