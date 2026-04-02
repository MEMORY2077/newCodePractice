#include <vector>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long int>row(m+1,0);
        vector<long long int>col(n+1,0);
        long long int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i+1]+=grid[i][j];
                col[j+1]+=grid[i][j];
                sum+=grid[i][j];
            }
        }
        if(sum%2==1)return false;
        sum/=2;
        for(int i=1;i<=m;i++){
            row[i]+=row[i-1];
            if(row[i]==sum)return true;
        }
        for(int j=1;j<=n;j++){
            col[j]+=col[j-1];
            if(col[j]==sum)return true;
        }
        return false;
    }
};