#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        int m=costs[0].size();
        vector dp(n,vector<int>(m,0x3f3f3f3f));
        for(int i=0;i<m;i++){
            dp[0][i]=costs[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    if(j!=k)dp[i][j]=min(dp[i-1][k]+costs[i][j],dp[i][j]);
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};