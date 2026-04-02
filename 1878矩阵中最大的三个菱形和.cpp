#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        diag_sum=vector<vector<int>>(m+1,vector<int>(n+1,0));
        anti_sum=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int v=grid[i][j];
                diag_sum[i+1][j+1]=diag_sum[i][j]+v;
                anti_sum[i+1][j]=anti_sum[i][j+1]+v;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                update(grid[i][j]);
                int mx=min({i,m-1-i,j,n-1-j});
                for(int k=1;k<=mx;k++){
                    int a=query_diagonal(i-k,j,k);
                    int b=query_diagonal(i,j-k,k);
                    int c=query_anti(i-k+1,j-1,k-1);
                    int d=query_anti(i,j+k,k+1);
                    update(a+b+c+d);
                }
            }
        }
        vector<int>ans={x,y,z};
        while(ans.back()==0){
            ans.pop_back();
        }
        return ans;
    }
private:
    vector<vector<int>>diag_sum;
    vector<vector<int>>anti_sum;
    int query_diagonal(int x,int y,int k){
        return diag_sum[x+k][y+k]-diag_sum[x][y];
    }
    int query_anti(int x,int y,int k){
        return anti_sum[x+k][y+1-k]-anti_sum[x][y+1];
    }
    void update(int v){
        if(v>x){
            z=y;
            y=x;
            x=v;
        }
        else if(v<x&&v>y){
            z=y;
            y=v;
        }
        else if(v<y&&v>z){
            z=v;
        }
    }
    int x=0;
    int y=0;
    int z=0;
};