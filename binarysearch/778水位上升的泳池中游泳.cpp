#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int maximum=0;
            n=grid.size();
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    maximum=max(grid[i][j],maximum);
                }
            }
            int left=grid[n-1][n-1];
            int right=maximum;
            int ans=0;
            //cout<<right;
            while(left<=right){
                int mid=(right-left)/2+left;
                if(swim(grid,mid)){
                    ans=mid;
                    right=mid-1;
                    continue;
                }
                else{
                    left=mid+1;
                    continue;
                }
            }
            return ans;
        }
        bool swim(vector<vector<int>>grid,int time){
            if(grid[0][0]>time)return false;
            int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            queue<pair<int,int>>q;
            q.push({0,0});
            grid[0][0]=-1;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]>=0&&grid[nx][ny]<=time){
                        if(nx==n-1&&ny==n-1)return true;
                        q.push({nx,ny});
                        grid[nx][ny]=-1;
                    }
                }
            }
            return false;
        }
        int n;
        int t=0;
    };