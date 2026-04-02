#include <vector>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(grid[0][0]>k)return 0;
        int ans=1;
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
            if(dp[0][i]<=k)ans++;
        }
        for(int j=1;j<m;j++){
            dp[j][0]=dp[j-1][0]+grid[j][0];
            if(dp[j][0]<=k)ans++;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i][j];
                if(dp[i][j]<=k)ans++;
            }
        }
        return ans;
    }
};