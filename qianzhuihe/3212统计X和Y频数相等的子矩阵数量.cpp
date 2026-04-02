#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char x=grid[i][j];
                dp[i+1][j+1][0]=dp[i][j+1][0]+dp[i+1][j][0]-dp[i][j][0];
                dp[i+1][j+1][1]=dp[i][j+1][1]+dp[i+1][j][1]-dp[i][j][1];
                if(x=='X')dp[i+1][j+1][0]++;
                else if(x=='Y')dp[i+1][j+1][1]++;
               // cout<<x<<' '<<dp[i+1][j+1][x]<<' ';
                if(dp[i+1][j+1][0]>0&&dp[i+1][j+1][0]==dp[i+1][j+1][1])ans++;
            }
        }
        return ans;
    }
};