#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>dpd(m,vector<long long>(n,1));
        vector<vector<long long>>dpx(m,vector<long long>(n,1));
        dpd[0][0]=grid[0][0];
        dpx[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dpd[i][0]=dpd[i-1][0]*grid[i][0];
            dpx[i][0]=dpx[i-1][0]*grid[i][0];
        }
        for(int i=1;i<n;i++){
            dpd[0][i]=dpd[0][i-1]*grid[0][i];
            dpx[0][i]=dpx[0][i-1]*grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dpd[i][j]=max({dpd[i-1][j]*grid[i][j],dpd[i][j-1]*grid[i][j],dpx[i-1][j]*grid[i][j],dpx[i][j-1]*grid[i][j]});
                dpx[i][j]=min({dpd[i-1][j]*grid[i][j],dpd[i][j-1]*grid[i][j],dpx[i-1][j]*grid[i][j],dpx[i][j-1]*grid[i][j]});
            }
        }
        if(dpd[m-1][n-1]<0)return -1;
        return dpd[m-1][n-1]%1000000007;
    }
};