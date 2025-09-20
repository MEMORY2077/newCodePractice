#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
       return min(solve(grid),solve(rorate(grid))); 
    }
    int minArea(vector<vector<int>>grid,int l,int r,int u,int d){
        int left=r;
        int right=0;
        int top=d;
        int bottom=0;
        for(int i=u;i<d;i++){
            for(int j=l;j<r;j++){
                if(grid[i][j]){
                    left=min(left,j);
                    right=max(right,j);
                    top=min(top,i);
                    bottom=max(bottom,i);
                }
            }
        }
        return (right-left+1)*(bottom-top+1);
    }
    int solve(vector<vector<int>>grid){
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MAX;
        //1. 横着三块
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int area=minArea(grid,0,n,0,i);
                area+=minArea(grid,0,n,i,j);
                area+=minArea(grid,0,n,j,m);
                ans=min(area,ans);
            }
        }
        //2.上一下二
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=minArea(grid,0,n,0,j);
                area+=minArea(grid,0,j,i,m);
                area+=minArea(grid,j,n,i,m);
                ans=min(area,ans);
            }
        }
        //3.上二下一
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=minArea(grid,0,j,0,i);
                area+=minArea(grid,j,n,0,i);
                area+=minArea(grid,0,n,i,m);
                ans=min(area,ans);
            }
        }
        return 0;
    }
    vector<vector<int>>rorate(vector<vector<int>>grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ro(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ro[m-j-1][i]=grid[i][j];
            }
        }
        return ro;
    }
};