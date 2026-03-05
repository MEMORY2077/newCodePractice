#include <vector>
using namespace std;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector row_sum(m,vector<int>(n+1));
        vector col_sum(n,vector<int>(m+1));
        vector diag_sum(m+1,vector<int>(n+1));
        vector anti_sum(n+1,vector<int>(m+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=grid[i][j];
                row_sum[i][j+1]=row_sum[i][j]+x;
                col_sum[i+1][j]=col_sum[i][j]+x;
                diag_sum[i+1][j+1]=diag_sum[i][j]+x;
                anti_sum[i+1][j]=anti_sum[i][j+1]+x;
            }
        }
        for(int k=min(m,n);;k--){
            for(int i=k;i<=m;i++){
                for(int j=k;j<=n;j++){
                    int sum=diag_sum[i][j]-diag_sum[i-k][j-k];
                    if(anti_sum[i][j-k]-anti_sum[i-k][j]!=sum){
                        continue;
                    }
                    bool ok =true;
                    for(int r=i-k;r<i;r++){
                        if(row_sum[r][j]-row_sum[r][j-k]!=sum){
                            ok=false;
                            break;
                        }
                    }
                    if(!ok)continue;
                    for(int c=j-k;c<j;c++){
                        if(col_sum[i][c]-col_sum[i-k][c]!=sum){
                            ok=false;
                            continue;
                        }
                    }
                    if(ok)return k;
                }
            }
        }
    }
};