#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        const int MOD=1000000007;
        int numberOfPaths(vector<vector<int>>& grid, int k) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<unordered_map<int,int>>>div(m,vector<unordered_map<int,int>>(n));
            div[0][0][grid[0][0]%k]=1;
            int sum=grid[0][0];
            for(int i=1;i<n;i++){
                sum+=grid[0][i];
                div[0][i][(sum)%k]=1;
            }
            sum=grid[0][0];
            for(int i=1;i<m;i++){
                sum+=grid[i][0];
                div[i][0][sum%k]=1;
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    for(auto [last,count]:div[i-1][j]){
                        int now=(last+grid[i][j])%k;
                        div[i][j][now]=(div[i][j][now]+count)%MOD;
                    }
                    for(auto [last,count]:div[i][j-1]){
                        int now=(last+grid[i][j])%k;
                        div[i][j][now]=(div[i][j][now]+count)%MOD;
                    }
                }
            }
            return div[m-1][n-1][0];
        }
    };